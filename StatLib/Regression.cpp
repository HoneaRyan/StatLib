#include "StatLib.h"
#include <cmath>
#include <cmath>
#include <iostream>

namespace StatLib {
	std::vector<double> Regression::linearModelCoefficients(std::vector<double> xs, std::vector<double> ys) {
		double slope;
		double intercept;
		std::vector<double> coefficients;
		slope = Coefficients::PearsonCorrelation(xs, ys) *
			(SummaryStatistics::stdev(ys) / SummaryStatistics::stdev(xs));
		intercept = SummaryStatistics::mean(ys) - slope*SummaryStatistics::mean(xs);
		coefficients.push_back(intercept);
		coefficients.push_back(slope);
		return coefficients;
	}

	std::vector<double> Regression::generalLinearModelCoefficients(std::vector<std::vector<double>> vals) {
		double *matX;
		matX = new double[vals.size()*vals[0].size()];
		for (int i = 0; i < vals[0].size(); i++) {
			matX[i*vals.size()] = 1;
			for (int j = 1; j < vals.size(); j++) {
				matX[i*vals.size() + j] = vals[j][i];
			}
		}

		// to be completed
	}

	double Regression::predict(std::vector<double> coeffs, std::vector<double> vals) {
		double y = coeffs[0];
		for (int i = 1; i < coeffs.size(); i++) {
			y += coeffs[i] * vals[i - 1];
		}
		return y;
	}
}