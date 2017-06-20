// StatLib.h
// Contains the header for many different classes to be utilized for statistical analytics
// All functions support vectors and arrays
#pragma once
#include <vector>
#include <cmath>
#include <string>
#include <iostream>

namespace StatLib
{
	class SummaryStatistics
	{
	public:
		static double mean(std::vector<double>);
		static double mean(double*, int);
		static double variance(std::vector<double>);
		static double variance(double*, int);
		static double stdev(std::vector<double>);
		static double stdev(double*, int);
		static double covariance(std::vector<double>, std::vector<double>);
		static double covariance(double*, double*, int);

	};

	class Coefficients {
	public:
		static double PearsonCorrelation(double*, double*, int);
		static double PearsonCorrelation(std::vector<double> xs, std::vector<double> ys);
		static double SpearmansRankCorrelation(std::vector<double> xs, std::vector<double> ys);
		static double SpearmansUniqueRankCorrelation(std::vector<double> xs, std::vector<double> ys);
	};

	class Regression {
	public:
		static std::vector<double> linearModelCoefficients(std::vector<double>, std::vector<double>);
		std::vector<double> generalLinearModelCoefficients(std::vector<std::vector<double>> vals);
		double predict(std::vector<double> coeffs, std::vector<double> vals);
	};
}