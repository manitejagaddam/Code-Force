#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


const string NOTES[] = {
    "C", "C#", "D", "D#", "E", "F",
    "F#", "G", "G#", "A", "B", "H"
};
int get_index(const string& note) {
    for (int i = 0; i < 12; ++i) {
        if (NOTES[i] == note) {
            return i;
        }
    }
    return -1; 
}
int get_distance(int start_index, int end_index) {
    return (end_index - start_index + 12) % 12;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> note_names(3);
    for (int i = 0; i < 3; ++i) {
        cin >> note_names[i];
    }

    vector<int> indices(3);
    for (int i = 0; i < 3; ++i) {
        indices[i] = get_index(note_names[i]);
    }



    vector<int> p = {0, 1, 2};
    string result = "strange";

    bool found = false;

    do {
        int i1 = indices[p[0]]; 
        int i2 = indices[p[1]]; 
        int i3 = indices[p[2]]; 

        int d_XY = get_distance(i1, i2);
        int d_YZ = get_distance(i2, i3);

        if (d_XY == 4 && d_YZ == 3) {
            result = "major";
            found = true;
            break;
        }

        if (d_XY == 3 && d_YZ == 4) {
            result = "minor";
            found = true;
            break;
        }

    } while (next_permutation(p.begin(), p.end()));

    cout << result << "\n";

    return 0;
}