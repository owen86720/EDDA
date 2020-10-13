#include <vtkm/cont/DataSet.h>
#include <vtkm/worklet/FieldHistogram2.h>
#include <vtkm/cont/testing/Testing.h>
#include "dataset/Grid.h"
#include "dataset/DataSet.h"
#include "distribution/Histogram.h"


DataSet LoadAsHistogram(std::string fileName, int xVerts, int yVerts, int zVerts, int xBlockSize, int yBlockSize, int zBlockSize, int numberOfBins) {
    float f;
    int i = 0;
    const int nVerts = xVerts * yVerts * zVerts;
    vtkm::Float32* data = (vtkm::Float32*)malloc(nVerts * sizeof(vtkm::Float32));
    //std::vector<float> data ;
    std::ifstream fileIn(fileName, std::ios::binary);
    while (fileIn.read(reinterpret_cast<char*>(&f), sizeof(float))) {
        data[i++] = f;
        //data.push_back(f);
    }
    const int xCells = xVerts - 1;
    const int yCells = yVerts - 1;
    const int zCells = zVerts - 1;
    const int nCells = xCells * yCells * zCells;
    /*
    vtkm::cont::DataSet dataSet;
    vtkm::cont::ArrayHandleUniformPointCoordinates coordinates(vtkm::Id3(xVerts, yVerts, zVerts));
    dataSet.AddCoordinateSystem(vtkm::cont::CoordinateSystem("coordinates", coordinates));

    // Set point scalars
    dataSet.AddField(vtkm::cont::make_Field(
        "p_data", vtkm::cont::Field::Association::POINTS, data, nVerts, vtkm::CopyFlag::On));

    // Set cell scalars
    dataSet.AddField(vtkm::cont::make_Field(
        "c_data", vtkm::cont::Field::Association::CELL_SET, data, nCells, vtkm::CopyFlag::On));

    vtkm::cont::CellSetStructured<3> cellSet;

    //Set regular structure
    cellSet.SetPointDimensions(vtkm::make_Vec(xVerts, yVerts, zVerts));
    dataSet.SetCellSet(cellSet);
    //free(data);
    //return dataSet;
    */

    
    //DistributionArray hisA(data, nVerts, xBlockSize, yBlockSize, zBlockSize, numberOfBins);
    DistributionArray hisA;
    int N = nVerts / (xBlockSize * yBlockSize * zBlockSize);
    for (int i = 0; i < N; i++) {
        std::vector<float> temp;
        for(int j=0;j<xBlockSize*yBlockSize*zBlockSize;j++){
            temp.push_back(data[xBlockSize*yBlockSize*zBlockSize*i+j]);
        }
        //Histogram his(temp,xBlockSize*yBlockSize*zBlockSize,3);
        hisA.DisArray.push_back(new Histogram(temp, xBlockSize * yBlockSize * zBlockSize, 3));
    }
    DataSet ds(hisA);
    return ds;
    // Histogram his(data,i,10);
    // free(data);
    // his.Print();
    // his.Save(fileName);
}