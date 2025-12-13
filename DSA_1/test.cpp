int add(int a, int b){
    int c = 20 ; 
    c = c+a+b; 

    return c;
}

int main(){
    int a = 5, b= 10 , res; 
    res = add(a,b);
    res = res + a+ b; 
}