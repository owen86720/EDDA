#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <vector>
#include <algorithm>
#include "Distribution.h"

//template <typename T>
class Histogram : public Distribution{
    public:
        int numberOfBins;
        int dataLen;
        float binDelta;
        std::vector<float> fieldArray;
        std::vector<float> binArray;

        Histogram(float *data , int dataLen , int numberOfBins){
            this->numberOfBins = numberOfBins;
            this->dataLen = dataLen;
            for(int i = 0; i< dataLen ;i++){
                fieldArray.push_back(data[i]);
                //std::cout << data[i] <<" ";
            }
            maxValue = *std::max_element(fieldArray.begin(), fieldArray.end());
            minValue = *std::min_element(fieldArray.begin(), fieldArray.end());
            //std::cout << maxValue << "\n" << minValue << "\n";
            binDelta = (maxValue - minValue)/numberOfBins;

            Run();
        }

        Histogram(std::vector<float> data , int dataLen , int numberOfBins){
            this->numberOfBins = numberOfBins;
            this->dataLen = dataLen;
            fieldArray = data;
            maxValue = *std::max_element(fieldArray.begin(), fieldArray.end());
            minValue = *std::min_element(fieldArray.begin(), fieldArray.end());
            //std::cout << maxValue << "\n" << minValue << "\n";
            binDelta = (maxValue - minValue)/numberOfBins;

            Run();
        }

        void Run(){
            for(int i = 0;i< numberOfBins;i++){
                int count = 0;
                for(int j =0 ; j<dataLen;j++){
                    if(fieldArray.at(j) < (minValue+(i+1)*binDelta))
                        count++;
                }
                int temp = 0;
                for(int j = 0;j<i;j++){
                    temp += binArray.at(j);
                }
                count -= temp;
                binArray.push_back(count);
            }
        }

        void Print(){
            for(int i = 0; i< numberOfBins; i++){
                float lo = minValue + i*binDelta;
                float hi = lo + binDelta;
                std::cout << "  BIN[" << i << "] Range[" << lo << ", " << hi << "] = " << binArray.at(i) << std::endl;
            }
        }

        void Save(std::string fileName){
            fileName = fileName.substr(0,fileName.find(".")) + ".edda";
            //std::cout << fileName << "\n";
            std::ofstream fileOut(fileName,std::ios::out | std::ios::binary | std::ios::app);
            fileOut.write(reinterpret_cast<const char*>(&numberOfBins),sizeof(int));
            fileOut.write(reinterpret_cast<const char*>(&dataLen),sizeof(int));
            for(int i = 0; i< numberOfBins; i++){
                fileOut.write(reinterpret_cast<const char*>(&binArray.at(i)),sizeof(float));
            }
            fileOut.close();
        }
};

#endif // !HISTOGRAM_H