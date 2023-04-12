#include <iostream>
#include <fstream>
using namespace std;

int main(){
    char header[44];
    short data[1000];
    ifstream myfile("mywave.wav", ios::in | ios::binary);
    if(!myfile) {
        cout << "mywave.wav\n";
        return 666;
    }
    myfile.read(header, 44);
    unsigned int* SampleRate;
    
    SampleRate = (unsigned int*)(header + 24);
    unsigned int* ByteRate;
    ByteRate = (unsigned int*)(header + 28);
    cout << "SampleRate = " << * SampleRate<<endl;
    float a = *SampleRate;
    cout << "ByteRate = " << *ByteRate << endl;
    myfile.read((char*)data, 1000);
    ofstream song("song.txt");
    float dt = 1 / a;
    for (int i=0; i < 500; i++) {
        cout << (float)i * dt << " " << data[i * 2] << " " << data[i * 2 + 1] << endl;
        song << (float)i * dt << " " << data[i * 2] << " " << data[i * 2 + 1] << endl;
    }

}