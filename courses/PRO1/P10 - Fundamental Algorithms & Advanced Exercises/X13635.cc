#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Track {
  string artist, title, genre;
  int year;
};

bool comp(const Track &a, const Track &b) {
	
	if(a.artist < b.artist) return true;
	if(a.artist > b.artist) return false;
	if(a.year > b.year) return false;
	if(a.year < b.year) return true;
	return a.title < b.title;
	
		
}

vector<Track> read_tracks(int n) {
	
	vector<Track> llista(n);

	for(int i = 0; i < n; ++i) cin >> llista[i].artist >>  llista[i].title >>  llista[i].genre >>  llista[i].year;
	return llista;
}

void print_track(const Track &t) {
  cout << t.artist;
  cout << " (" << t.year;
  cout << ") " << t.title << " (" << t.genre << ")" << endl;
}

int main() {
  
 	int n;
  
  	cin >> n;
  	
  	vector<Track> llista = read_tracks(n);
  
	string gen;
   
    while(cin >> gen){
   		
		sort(llista.begin(),llista.end(), comp);
		
		for(int i = 0; i < n; ++i){
			if(llista[i].genre == gen) print_track(llista[i]);
		}
	   	
    }
}
