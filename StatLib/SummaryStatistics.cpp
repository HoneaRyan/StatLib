#include "StatLib.h"
#include <cmath>
#include <cmath>
#include <iostream>

// Helper Functions
std::vector<double> vectorize(double* vals, int n);








namespace StatLib {
	double SummaryStatistics::mean(std::vector<double> values) {
		std::vector<double>::iterator it;
		double sum = 0;
		for (it = values.begin(); it != values.end(); it++) {
			sum += *it;
		}
		return sum / values.size();
	}

	double SummaryStatistics::mean(double* values, int n) {
		std::vector<double> vec = vectorize(values, n);
		SummaryStatistics::mean(vec);
	}

	double SummaryStatistics::variance(std::vector<double> values) {
		double mean = SummaryStatistics::mean(values);
		std::vector<double>::iterator it;
		double sse = 0;
		for (it = values.begin(); it != values.end(); it++) {
			sse += pow(*it - mean, 2);
		}
		return sse / (values.size() - 1);
	}

	double SummaryStatistics::variance(double* values, int n) {
		std::vector<double> vec = vectorize(values, n);
		SummaryStatistics::variance(vec);
	}

	double SummaryStatistics::stdev(std::vector<double> values) {
		return sqrt(SummaryStatistics::variance(values));
	}

	double SummaryStatistics::stdev(double* values, int n) {
		std::vector<double> vec = vectorize(values, n);
		SummaryStatistics::stdev(vec);
	}

	double SummaryStatistics::covariance(std::vector<double> xs, std::vector<double> ys) {
		double xmean = SummaryStatistics::mean(xs);
		double ymean = SummaryStatistics::mean(ys);
		double sum = 0;
		for (int i = 0; i < xs.size(); i++) {
			sum += (xs[i] - xmean)*(ys[i] - ymean);
		}
		return sum / (xs.size() - 1);
	}

	double SummaryStatistics::covariance(double* xs, double* ys, int n) {
		std::vector<double> vecx = vectorize(xs, n);
		std::vector<double> vecy = vectorize(ys, n);
		return SummaryStatistics::covariance(vecx,vecy);
	}
}








// Helper Functions
// turns arrays into vectors
std::vector<double> vectorize(double* vals, int n) {
	std::vector<double> vec;
	for (int i = 0; i < n; i++) {
		vec.push_back(vals[i]);
	}
	return vec;
}