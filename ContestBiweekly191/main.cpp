#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

/// <summary>
/// Count Values With Equally Spaced Occurrences I
/// </summary>
class SolutionQ1 {
public:
	// Map of element int to its occurence indexes array
	unordered_map<int, vector<int>> elementOccurences;
	unordered_map<int, bool> elementFailures;

	bool addElementIndex(int el, int index) {
		// Has reached limit
		if (elementOccurences[el].size() == 3) {
			elementFailures[el] = true;
			return false;
		}

		// Quit if failed.
		if (elementFailures[el]) {
			return false;
		}

		// Handle equal spacing checks
		int n = elementOccurences[el].size();
		if (n > 1) {
			int indexR = elementOccurences[el][n - 1];
			int indexL = elementOccurences[el][n - 2];
			int previousSpacing = indexR - indexL;

			// Doesnt match required gap of 3
			if (index - indexR != previousSpacing) {
				elementFailures[el] = true;
				return false;
			}
		}

		// No issues, add.
		elementOccurences[el].push_back(index);
		return true;
	}

	int countSpecialIntegers(vector<int>& nums) {
		set<int> uniqueNums;
		for (int i = 0; i < nums.size(); i++) {
			addElementIndex(nums[i], i);
			uniqueNums.insert(nums[i]);
		}

		int succeeded = 0;
		for (auto& el : uniqueNums) {
			if (!elementFailures[el] && elementOccurences[el].size() == 3) {
				succeeded++;
			}
		}

		return succeeded;
	}
};

/// <summary>
/// Count Values With Equally Spaced Occurrences II
/// </summary>
class SolutionQ2 {
public:
	// Map of element int to its occurence indexes array
	unordered_map<int, vector<int>> elementOccurences;
	unordered_map<int, bool> elementFailures;

	bool addElementIndex(int el, int index) {
		// Quit if failed.
		if (elementFailures[el]) {
			return false;
		}

		// Handle equal spacing checks
		int n = elementOccurences[el].size();
		if (n > 1) {
			int indexR = elementOccurences[el][n - 1];
			int indexL = elementOccurences[el][n - 2];
			int previousSpacing = indexR - indexL;

			// Doesnt match required gap of 3
			if (index - indexR != previousSpacing) {
				elementFailures[el] = true;
				return false;
			}
		}

		// No issues, add.
		elementOccurences[el].push_back(index);
		return true;
	}

	int countSpecialIntegers(vector<int>& nums) {
		set<int> uniqueNums;
		for (int i = 0; i < nums.size(); i++) {
			addElementIndex(nums[i], i);
			uniqueNums.insert(nums[i]);
		}

		int succeeded = 0;
		for (auto& el : uniqueNums) {
			if (!elementFailures[el] && elementOccurences[el].size() >= 3) {
				succeeded++;
			}
		}

		return succeeded;
	}
};

/// <summary>
/// Minimum Days to Score Exactly N Points
/// </summary>
class SolutionQ3 {
public:
	vector<int> streakDays(int n) {


	}

	int minDays(int n) {
		if (n == 0) return 0;
		if (n == 1) return 1;
		int daysNeeded = 0;
		int streak = 1;
		int iterations = 0;
		set<int> toSkip;
		while (daysNeeded != n && toSkip.size() != n) {
			for (int i = 0; i < n; i++) {
				if (toSkip.contains(i)) {
					streak = 1;
					continue;
				}
				daysNeeded += streak++;
			}
			//toSkip.iterations++
		}
		return daysNeeded;
	}
};

/// <summary>
/// Count Subarrays with Distant Sums
/// </summary>
class SolutionQ4 {
public:
	long long distantSubarrays(vector<int>& nums, int goal, int k) {
		long long arrs = 0;

		// Outer loop, controls current subarray size 
		for (int take = 1; take <= nums.size(); take++) {
			int num = 0;
			// Inner loop, builds subarrays and their sums, derives valid arrays
			for (int i = 0; i <= nums.size() - take; i++) {
				int sum = 0;

				// Sum substring
				for (int j = i; j < i + take; j++) {
					sum += nums[j];
				}
				// Valid substring
				if (abs(sum - goal) >= k) {
					num++;
				}
			}
			arrs += num;
		}

		return arrs;
	}
};

int _main() {
	SolutionQ4 sol;
	vector<int> v = { 53167,-132928,169828,86577,173660,82138,161157,-176617,-45798,146727,3554,143761,90928,211338,52413,137526,185892,40100,210593,-15738,118200,198962,-181934,69788,200026,81304,-120329,-97335,-17383,-34271,-14924,-147999,134557,-21644,197020,161725,-57741,-163457,201919,52361,-102118,30315,-153256,-153783,-159185,-164113,188668,-106324,68680,99866,-155436,155255,163310,-150217,185966,-68765,-125820,73138,84226,187744,-147919,-169119,-204051,77835,-46857,-209197,142642,127247,82419,-156358,94345,-46164,-42912,47292,199376,-52449,17019,-120563,-111112,141615,-5221,-72471,-97054,38718,26152,195923,-81843,109454,-190082,-69718,209377,210961,203834,156356,-189601,-84887,21616,118594,120131,13559,197995,-122288,-153908,146283,-76303,-209663,-89875,149891,95633,84078,128310,95908,84135,-210437,-73771,181979,-96705,99795,-184313,158516,80500,159513,160016,-4414,-205433,-95650,-97284,-108329,-5522,-81504,189418,-69564,88774,-117313,-4372,191217,-44090,76271,185526,-31836,36824,-94981,-53322,7734,-159993,-65921,-116263,11981,-21211,-96458,-128779,5797,109903,-152782,-82935,-184292,171132,-191743,160302,-139403,60493,125576,-32426,-450,-43133,126324,78135,83318,148769,-16169,180326,79834,-7083,-49317,-130279,-99871,-49588,94031,102312,-131724,-148367,100508,-16746,-101326,-15401,131324,3322,22892,69014,197804,-31395,62226,24140,124976,-168372,132304,67672,166522,100844,10362,-82356,128497,56151,-27129,-50350,-62713,206249,170304,98074,-130127,46354,-52746,-78654,-205889,198815,-77569,42802,-54523,7321,-41366,143090,-96397,112868,-92016,78122,-12592,-65827,151572,-87420,-208194,-157729,48899,-17780,-96196,128640,170991,-112120,202216,-143224,-60215,-17939,95523,34069,167928,82666,-49500,155564,-52925,42985,37044,118128,81377,59321,92649,6962,198905,-167363,81404,-33086,84659,149115,-43307,144829,16459,-40666,-891,-209893,9461,-133500,97244,-210294,128803,-178801,-169093,-146573,10380,-10056,13152,-18708,-99169,44588,184177,-176592,-148085,-160826,-141445,151759,-122823,136067,-127957,37775,135785,-110827,-140213,-34503,-163292,207761,45035,178302,-41795,146469,126962,48614,-141432,-152629,-65317,-117647,-159184,86354,151941,-196262,-134688,20761,211595,-28387,30366,-122177,65836,-116399,-148397,-7460,-119601,-201933,203811,68441,-64514,-154918,190682,147389,-72225,32645,-104349,130840,26168,-152713,-159946,186162,-17154,-156599,62824,-205367,46425,-200468,-83703,199188,-102787,7400,-172621,-204954,172686,76412,143237,134691,-42435,182839,36023,109887,-191925,-138683,-11690,-9600,-67753,-29916,-110678,33753,95591,11058,-146230,-24756,61599,-115043,-38967,132526,153782,121050,38866,-176834,12672,202912,-153072,-26531,-57677,-77649,5065,67138,-140502,43746,-58250,11522,97523,96552,137561,-32276,-94410,68253,-80915,189791,-102318,-158797,-3347,160378,140651,29631,69504,118928,94143,123502,-36697,153722,-133891,-67353,-97254,-113302,81997,46758,-101139,-15201,-33080,111799,-80940,-66726,141335,-4624,102951,8640,3483,59868,154588,72640,126322,25004,1540,-158962,14975,-95565,194238,-13104,205912,-129564,-209261,138412,146275,-202409,-82254,-126794,-208600,-152000,46135,147616,-166080,57035,-138236,76074,-99954,-80532,124452,-38763,-35721,-68870,17292 };
	cout << sol.distantSubarrays(v, 133167, 99179) << endl;
	return 0;
}
