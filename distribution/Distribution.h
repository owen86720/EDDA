#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H


class Distribution {
	public:
		virtual void Print()=0;
	//	virtual int getSample()=0;
	protected:
		double maxValue;
		double minValue;

};

#endif // !DISTRIBUTION_H