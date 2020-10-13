#ifndef DISTRIBUTION_ARRAY_H
#define DISTRIBUTION_ARRAY_H

#include <iostream>
#include <vector>
#include <string>
#include "distribution/Distribution.h"

class DistributionArray{
    public:
        std::vector<Distribution *> DisArray;

        //DistributionArray(float *data , int dataLen, int xBlockSize , int yBlockSize , int zBlockSize , int numberOfBins){
        //    int N = dataLen/(xBlockSize*yBlockSize*zBlockSize);
        //    for(int i = 0 ;i<N;i++){
        //        std::vector<float> temp;
        //        for(int j=0;j<xBlockSize*yBlockSize*zBlockSize;j++){
        //            temp.push_back(data[xBlockSize*yBlockSize*zBlockSize*i+j]);
        //        }
        //        Histogram his(temp,xBlockSize*yBlockSize*zBlockSize,3);
        //        DisArray.push_back(his);
        //    }
        //    //std::cout << "N:" << temp << "\n";

        //    
        //}

        //DistributionArray(std::vector<float> data , int dataLen, int xBlockSize , int yBlockSize , int zBlockSize , int numberOfBins){
        //    int N = dataLen/(xBlockSize*yBlockSize*zBlockSize);
        //    for(int i = 0 ;i<N;i++){
        //        std::vector<float> temp;
        //        for(int j=0;j<xBlockSize*yBlockSize*zBlockSize;j++){
        //            temp.push_back(data.at(xBlockSize*yBlockSize*zBlockSize*i+j));
        //        }
        //        Histogram his(temp,xBlockSize*yBlockSize*zBlockSize,3);
        //        DisArray.push_back(his);




        //    }
        //    //std::cout << "N:" << temp << "\n";

        //    


        //}

        void print(){
            for(int i =0;i< DisArray.size();i++){
                std::cout << "Histogram " << i << " :\n";
                DisArray.at(i)->Print();
            }
        }

        int getSize() {
            return DisArray.size();
        }

        void append(Distribution* data) {
            DisArray.push_back(data);
        }
};

#endif // !DISTRIBUTION_ARRAY_H