#include <iostream>
#include <Windows.h> // Sleep( )
#include <vector>
#include <fstream>

using namespace std;

int main() {
    int lost = 0;
    int NofPackets[120];
    int elapsedSeconds = 0, NI, NO, T = 1;
    int ni, no;
    cout << "RANDMAX: " << RAND_MAX << endl;
    while (elapsedSeconds < 120) {
        Sleep(T * 1000);  // milliseconds
        NI = rand() % 50;  // 0~49 random number
        NO = rand() % 50;  // 0~49 random number

        vector<int> queue;
        int capacity = 100;
        ni = rand() % NI;
        no = rand() % NO;
        if (capacity < queue.size() + ni) {
            lost += queue.size() + ni - capacity;
            cout << "lost: " << lost << endl;
            ni = capacity - queue.size();
        }
        for (int i = 0; i < ni; i++) {
            queue.push_back(rand() % 20);
        }

        for (int i = 0; i < no; i++) {
            if (!queue.empty()) { // no underflow
                cout << queue[0] << "\n";
                queue.erase(queue.begin());
            }
        }

        NofPackets[elapsedSeconds] = queue.size();

        cout << "Elapsed time[sec] = " << elapsedSeconds << "   " << "NI = " << NI << " NO = " << NO << endl;
        elapsedSeconds += T;
    }

    ofstream text("queue.txt");
    for (int i = 0; i < 120; i++) {
        text << i << " " << NofPackets[i] << endl;
    }
    text.close();

    return 123;
}
