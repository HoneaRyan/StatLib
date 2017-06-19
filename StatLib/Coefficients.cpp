#include "StatLib.h"
#include <cmath>
#include <cmath>
#include <algorithm>
#include <iostream>

namespace StatLib {
	double Coefficients::PearsonCorrelation(std::vector<double> xs, std::vector<double> ys) {
		double ystdev = SummaryStatistics::stdev(ys);
		double xstdev = SummaryStatistics::stdev(xs);
		return SummaryStatistics::covariance(xs, ys) / (ystdev * xstdev);
	}

	double Coefficients::SpearmansRankCorrelation(std::vector<double> xs, std::vector<double> ys) {

	}

	double Coefficients::SpearmansUniqueRankCorrelation(std::vector<double> xs, std::vector<double> ys) {
		std::vector<double> sortedXs = xs;
		std::vector<double> sortedYs = ys;
		std::vector<double> rankX;
		std::vector<double> rankY;
		rankX.reserve(10);
		rankY.reserve(10);
		std::sort(sortedXs.begin(), sortedXs.end());
		std::sort(sortedYs.begin(), sortedYs.end());

		for (int i = 0; i < xs.size(); i++) {
			for (int j = 0; j < xs.size(); j++) {
				if (xs[i] == sortedXs[j]) {
					rankX[i] = (double)(j);
				}
				if (ys[i] == sortedYs[j]) {
					rankY[i] = (double)(j);
				}
			}
		}

		double sumRankDif = 0;
		for (int i = 0; i < xs.size(); i++) {
			sumRankDif += pow(rankX[i] - rankY[i], 2);
		}
		return 1 - (6 * sumRankDif) / (pow(xs.size(), 3) - xs.size());
	}
}