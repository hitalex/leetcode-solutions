#include <iostream>

using namespace std;

int binary_search(int t, int a[], int n){
    int l, u;
    l = 0; u = n-1;
    
    int result = -1;
    int n_cmp = 0;
    while(true){
        if(l > u){
            n_cmp ++ ;
            result = -1;
            break;
        }
            
        int m = (l + u) / 2;
        if(a[m] == t){
            n_cmp ++ ;
            result = m;
            break;
        }
        else if(a[m] < t){
            n_cmp ++ ;
            l = m + 1;
        }else{
            u = m - 1;
        }
    }
    
    cout << "Number of cmps: " << n_cmp << endl;
    
    return result;
}

int binary_search_recursive(int t, int a[], int l, int u){
    if(l > u)
        return -1;
        
    int m = (l + u) / 2;
    if(a[m] == t)
        return m;
    else if(a[m] < t)
        return binary_search_recursive(t, a, m+1, u);
    else
        return binary_search_recursive(t, a, l, m-1);
}

// 返回首次出现的位置
int binary_search_v2(int t, int a[], int n){
    int l, u;
    l = 0; u = n-1;
    
    int n_cmp = 0;
    while(true){
        if(l > u){
            n_cmp ++ ;
            return -1;
        }
            
        int m = (l + u) / 2;
        if(a[m] > t){
            n_cmp ++ ;
            u = m - 1;
        }else if(a[m] < t){
            n_cmp ++ ;
            l = m + 1;
        }else{
            // a[m] == t
            if(a[m-1] == t){
                n_cmp ++ ;
                u = m - 1;
            }else{
                return m;
            }
        }
    }
}

int main(){
    int a[] = {1, 2, 2, 4, 6, 10, 10, 10, 20, 34};
    int n = 10;
    //cout << binary_search(10, a, n) << endl;
    cout << binary_search_recursive(10, a, 0, n-1) << endl;
}
