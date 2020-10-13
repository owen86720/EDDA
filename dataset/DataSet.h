#ifndef DATASET_H
#define DATASET_H

#include <vector>
#include "dataset/DistributionArray.h"
#include "dataset/Grid.h"


class DataSet {
	public :
		DistributionArray DisArr;
		Grid grid;
		DataSet(DistributionArray data) {
			DisArr.DisArray = data.DisArray;
			//for (int i = 0; i < data.getSize(); i++) {
			//	DisArr.append(data.DisArray.at(i));
			//}
		}

		void print() {
			DisArr.print();
		}
};

#endif // !DATASET_H