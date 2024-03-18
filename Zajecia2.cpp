#include <iostream>
#include <cmath>
#include <fstream>
#include <cfloat>

using namespace std;

double Function(double val) {
    return (1.0 - exp(-1.0 * val)) / val;
}

double RelativeError(double val1, double val2) {
    return fabs((val1 - val2) / val1);
}

double TaylorSeries(double val, double exact_result) {
    double result = 1.0, previous = 1.0, i = 1.0;
    while ((fabs(result - exact_result) > DBL_EPSILON)) {
        previous *= -val / (i + 1.0);
        result += previous;
        i += 1.0;
        if (previous == 0) {
            break;
        }
    }
    return result;
}

int main() {
    double logx, x, exact_result, computed_result, error;
    ifstream input_file;
    ofstream output_file;
    input_file.open("dane.txt", ios::in);
    output_file.open("results.txt", ios::out);
    cout.precision(20);

    cout << "Exact result: \tComputed result: \tRelative error:" << endl;

    while (input_file >> logx >> x >> exact_result) {
        if (logx > 0) {
            computed_result = Function(x);
        }
        else {
            computed_result = TaylorSeries(x, exact_result);
        }
        error = RelativeError(exact_result, computed_result);
        cout << exact_result << "\t" << computed_result << "\t" << error << endl;
        output_file << logx << "\t" << log10(error) << endl;
    }

    input_file.close();
    output_file.close();
}
