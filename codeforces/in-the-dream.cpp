#include <iostream>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; 
    cin >> n; 
    int a,b,c,d;
    for(int i=0; i<n; i++){
 
        cin >> a >> b >> c >> d; 
 
        // SHG = Second Half Goals
 
        int rSHG = c-a; 
        int kSHG = d-b; 
 
        int flag = 0; 
 
        if((max(a,b) <= 2*(min(a,b)+1)) && (max(rSHG,kSHG) <= 2*(min(rSHG, kSHG)+1))){
            flag = 1; 
        }
 
        if(flag){
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
            
    }
    
    return 0;
}
