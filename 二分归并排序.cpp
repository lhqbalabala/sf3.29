#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn];
void merge(int *a,int l,int mid,int r){
	int k[r-l+1];
	int l1=l;
	int l2=mid+1;
	for(int i=0;i<r-l+1;i++){
		if(l1>mid){
			while(l2<=r){
				k[i++]=a[l2++];
			}
		}
		else if(l2>r){
			while(l1<=mid){
				k[i++]=a[l1++];
			}
		}
		else if(a[l1]<a[l2]){
			k[i]=a[l1++];
		}
		else k[i]=a[l2++];
	}
	for(int i=0;i<r-l+1;i++){
		a[l+i]=k[i];
	}
	return;
}
void mergeSort(int *a,int l,int r){
	if(l>=r)return;
	int mid=(l+r)/2;
	mergeSort(a,l,mid);
	mergeSort(a,mid+1,r);
	merge(a,l,mid,r);
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	mergeSort(a,1,n);
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	puts("");
}
