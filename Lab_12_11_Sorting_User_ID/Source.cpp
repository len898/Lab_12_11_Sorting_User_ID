#include <string>
#include <vector>
#include <iostream>

using namespace std;

// TODO: Write the partitioning algorithm - pick the middle element as the
//       pivot, compare the values using two index variables l and h (low and high),
//       initialized to the left and right sides of the current elements being sorted,
//       and determine if a swap is necessary
int Partition(vector<string>& userIDs, int i, int k) {
	int midpoint = i + (k - i) / 2;
	string pivot = userIDs.at(midpoint);

	int l = i;
	int h = k;
	bool done = false;
	while (!done) {
		while (userIDs.at(l) < pivot) {
			++l;
		}
		while (pivot < userIDs.at(h)) {
			--h;
		}
		if (l >= h) {
			done = true;
		}
		else {
			string temp = userIDs.at(l);
			userIDs.at(l) = userIDs.at(h);
			userIDs.at(h) = temp;
			++l;
			--h;
		}
	}
	return h;

}

// TODO: Write the quicksort algorithm that recursively sorts the low and
//       high partitions
void Quicksort(vector<string>& userIDs, int i, int k) {
	int j;

	if (i >= k) {
		return;
	}
	j = Partition(userIDs, i, k);
	Quicksort(userIDs, i, j);
	Quicksort(userIDs, j + 1, k);
}

int main() {
	vector<string> userIDList;
	string userID;

	cin >> userID;
	while (userID != "-1") {
		userIDList.push_back(userID);
		cin >> userID;
	}

	// Initial call to quicksort
	Quicksort(userIDList, 0, userIDList.size() - 1);

	for (size_t i = 0; i < userIDList.size(); ++i) {
		cout << userIDList.at(i) << endl;;
	}

	return 0;
}