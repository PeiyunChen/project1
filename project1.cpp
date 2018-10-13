//project1 version 5
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<cstring>
#include<time.h>
using namespace std;

 vector< vector<long int> > vect;

int main(int argc, char* argv[])
{
    //openfile
    //time_t start=clock();

    char inftmp[15] = "/matrix.data";
    char inf[30];
    strcpy(inf,argv[1]);
    strcat(inf,inftmp);
    ifstream file;
	file.open(inf);

  char oftmp[15] = "/final.peak";
    char of[30];
    strcpy(of,argv[1]);
    strcat(of,oftmp);
    ofstream outfile;
    outfile.open(of);




    int row,col;
	int num=0;
	long int tmp;


    std::vector<int> vec;

    if(!file){
    	cout<<"fail to open"<<"\n";
	}
    else {
    	file>>row;
    	file>>col;

    	for(int i=0;i<row;i++){
            vector<long int> vt;
    		for(int j=0;j<col;j++){

    			file>>tmp;
                vt.push_back(tmp);

			}
            vect.push_back(vt);
		}



    	file.close();
		for(int i=0;i<row;i++){
   		for(int j=0;j<col;j++){
   			if(i==0&&j==0){//1
   				if(vect[i][j]>=vect[i+1][j]&&vect[i][j]>=vect[i][j+1]){
   					num++;
   					//outfile<<i+1<<" "<<j+1<<"\n";
   					vec.push_back(i+1);
   					vec.push_back(j+1);

				   }
			   }
			else if(i==0&&j==col-1){//2
				if(vect[i][j]>=vect[i+1][j]&&vect[i][j]>=vect[i][j-1]){
   					num++;
   					//outfile<<i+1<<" "<<j+1<<endl;
				   	vec.push_back(i+1);
   					vec.push_back(j+1);
				   }
			}
			else if(i==(row-1)&&j==(col-1)){ //3
				if( (vect[i][j]>=vect[i-1][j] ) && (vect[i][j]>=vect[i][j-1])){
   					num++;
   					//outfile<<i+1<<" "<<j+1<<endl;
				   	vec.push_back(i+1);
   					vec.push_back(j+1);
				   }
			}
			else if(i==(row-1) &&j==0){ //4
				if(vect[i][j]>=vect[i-1][j]&&vect[i][j]>=vect[i][j+1]){
   					num++;
   					//outfile<<i+1<<" "<<j+1<<endl;
				   	vec.push_back(i+1);
   					vec.push_back(j+1);
				   }
			}
			else if(i==0 &&j>0&&j<(col-1)){ //5
				if(vect[i][j]>=vect[i+1][j]&&vect[i][j]>=vect[i][j+1]&&vect[i][j]>=vect[i][j-1]){
   					num++;
   					//outfile<<i+1<<" "<<j+1<<endl;
				   	vec.push_back(i+1);
   					vec.push_back(j+1);
				   }
			}
			else if(i>0&&i<(row-1)&&j==(col-1)){ //6
				if(vect[i][j]>=vect[i+1][j]&&vect[i][j]>=vect[i-1][j]&&vect[i][j]>=vect[i][j-1]){
   					num++;
   					//outfile<<i+1<<" "<<j+1<<endl;
				   	vec.push_back(i+1);
   					vec.push_back(j+1);
				   }
			}
			else if(i==row-1&&j<(col-1)&&j>0){ //7
				if(vect[i][j]>=vect[i-1][j]&&vect[i][j]>=vect[i][j+1]&&vect[i][j]>=vect[i][j-1]){
   					num++;
   					//outfile<<i+1<<" "<<j+1<<endl;
				   	vec.push_back(i+1);
   					vec.push_back(j+1);
				   }
			}
			else if(i>0&&i<(row-1)&&j==0){ //8
                    //cout<<"kk\n";
				if(vect[i][j]>=vect[i-1][j]&&vect[i][j]>=vect[i+1][j]&&vect[i][j]>=vect[i][j+1]){
   					num++;

   					//outfile<<i+1<<" "<<j+1<<endl;
   					vec.push_back(i+1);
   					vec.push_back(j+1);
				   }
			}
			else{
				if(vect[i][j]>=vect[i-1][j]&&vect[i][j]>=vect[i+1][j]&&vect[i][j]>=vect[i][j+1]&&vect[i][j]>=vect[i][j-1]){
   					num++;
   					//outfile<<i+1<<" "<<j+1<<endl;
   					vec.push_back(i+1);
   					vec.push_back(j+1);
				   }
			}
		}
   		}
	}

   	outfile<<num<<endl;


   int count=0;
  for (auto a = vec.begin(); a != vec.end(); ++a) {
        count++;
   		outfile << *a << " ";
   		if(count%2==0){
   			outfile<<endl;
		   }
   }

	outfile.close();
	return 0;

}

