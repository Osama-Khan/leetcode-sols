#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

/// <summary>
/// Entry type for busy server heap
/// </summary>
using BusyServerEntry = pair<unsigned int, unsigned int>;

/// <summary>
/// Uses a set and priority queue to maintain free / busy server data. Tracks
/// max requests handled through the iterations and returns server IDs matching
/// the max requests handled value.
/// </summary>
class Solution {
private:
	/// <summary>
	/// Makes a set of server IDs based on given k.
	/// </summary>
	/// <param name="k">Number of servers</param>
	/// <returns>Set containing servers IDs 1..k</returns>
	set<unsigned int> makeFreeServersSet(int k) {
		vector<unsigned int> servers(k, 0);
		iota(servers.begin(), servers.end(), 0);
		return set<unsigned int>(servers.begin(), servers.end());
	}

public:
	vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
		// Servers that are free
		set<unsigned int> freeServers = makeFreeServersSet(k);
		// Queue of busy servers and their free up times
		// .first is time the server is busy until
		// .second is serverId
		priority_queue<BusyServerEntry, vector<BusyServerEntry>,
			greater<BusyServerEntry>>
			busyServers;
		// Requests handled by server at given index
		vector<int> serverRequestsHandled(k, 0);

		// The number of maximum requests handled by any server
		unsigned int maxHandled = 0;

		// Process request arrivals
		for (size_t i = 0; i < arrival.size(); i++) {
			// arrival time
			const int at = arrival[i];
			// request load
			const int ld = load[i];

			// Free up busy servers based on current `at`
			while (!busyServers.empty() && busyServers.top().first <= at) {
				freeServers.insert(busyServers.top().second);
				busyServers.pop();
			}

			// No free servers, drop.
			if (freeServers.empty())
				continue;

			auto itHandler = freeServers.lower_bound(i % k);
			if (itHandler == freeServers.end()) {
				// None available on the right, handler is the first available server
				itHandler = freeServers.begin();
			}

			// Update requests handled and tracked max
			serverRequestsHandled[*itHandler]++;
			if (serverRequestsHandled[*itHandler] > maxHandled) {
				maxHandled = serverRequestsHandled[*itHandler];
			}

			// Make server busy
			busyServers.push({ at + ld, *itHandler });
			freeServers.erase(itHandler);
		}

		// Find the servers with max handled requests
		vector<int> out;
		for (size_t i = 0; i < k; i++) {
			if (serverRequestsHandled[i] == maxHandled)
				out.push_back(i);
		}

		return out;
	}
};
