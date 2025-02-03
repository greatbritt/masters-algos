#include <iostream>
#include <string>

using namespace std;

int mySearch(string songArray[], int arraySize, const string &songName, int songIndex) {

    for (int i = 0; i < arraySize; i++){
        cout << i << ". " << songArray[i] << endl;  // Print Out Array to verify if value exists
    }

    int searchBegin = 0;
    int searchEnd = arraySize - 1;
    int pos1 = searchBegin + (searchEnd-searchBegin+1)/3;
    int pos2 = searchBegin + 2*(searchEnd-searchBegin+1)/3;
    songIndex = -1; // the initial value

    while(searchBegin < searchEnd && songIndex == -1){
        if ( songArray[searchBegin] > songName || songName >= songArray[pos1] ) {
            if ((songArray[pos1] <= songName) && (songName < songArray[pos2])) {
                for (int i = searchBegin; i < searchEnd; i++) {
                    if (songArray[i] == songName) {
                        songIndex = i;
                        return songIndex;
                    }
                }
            } else if ((songArray[pos2] <= songName) && songName < songArray[arraySize]) {
                for (int i = searchBegin; i < searchEnd; i++) {
                    if (songArray[i] == songName) {
                        songIndex = i;
                        return songIndex;
                    }
                }
            } else {
                songIndex = -1;
                return songIndex;
            }
        } else {
            for (int i = searchBegin; i < searchEnd; i++) {
                if (songArray[i] == songName) {
                    songIndex = i;
                    return songIndex;
                }
            }
        }
    }

}

int main(int argc, char** argv) {
    char ans;
      do {
        string songArray[] = {"All for the Love", "Blueslides", "California Love", "Dirty South", "Everybody Loves The Sunshine", "Feel A Way", "GET LIKE ME", "Hot Boyz", "Intimidated", "Justify My Thug", "King's Dead", "Late", "Magnolia", "No More Parties in LA", "Outside (Better Days)", "Part of the Deal", "Quantum Leap", "Reverse Time"};
        int arraySize = sizeof(songArray)/sizeof(string);
        string songName;

        cout << "Please Enter A Song Name..." << endl;
        getline (cin, songName);
        cout << endl;
        cout << "Searching for: " + songName << endl << endl;
        int songIndex = mySearch(songArray, arraySize, songName, songIndex);
        cout << endl;
        cout << "Index for song " << songName << " is " << songIndex << endl << endl;

          cout << "Do you want to search again (Y/N)?" << endl;
          cout << "You must type a 'Y' or an 'N' :";
          cin >> ans;   //unobserved trailing /n acting as "enter key strike"
          cin.ignore();



    } while ((ans == 'Y') || (ans == 'y'));

}


// Reference: https://www.physicsforums.com/threads/c-search-algorithm-with-3-sublists.852859/




// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.