#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

ifstream fin("hut.in");
ofstream fout("hut.out");

inline int sqr(int a) { return a * a; }

const double INFI = 1000000;
const int maxn = 50;
const int maxm = 50;

double f[101][maxm + 1][maxn + 1];
double k1, k2;

double calc(int l, int n)
{
	if (n == 0 || n > l) return INFI;
	return (l % n) * k2 * sqr(l / n + 1) + (n - l % n) * k2 * sqr(l / n) + k1 * sqr(l);
}

int main()
{
	int m, n, i, j, k, mm, nn;
	double x, y;
	fin >> k1 >> k2 >> m >> n;
	for (i = 0; i <= 100; i++) {
		for (j = 0; j <= 100; j++) {
			for (k = 0; k <= 100; k++) {
				f[i][j][k] = -1;
			}
		}
	}
	f[0][0][0] = 0;
	for (i = 1; i <= 100; i++) {
		for (nn = 1; nn <= maxn; nn++) {
			for (mm = 1; mm <= nn; mm++) {
				if (mm > maxm) break;
				f[i][mm][nn] = INFI;
				k = 1;
				if (mm == 1) k = nn;
				for (j = 1; i - j >= mm - 1; j++) {
					x = f[i - j][mm - 1][nn - k + 1];
					y = calc(j, k - 1);
					if (x != -1 && x + y < f[i][mm][nn])
						f[i][mm][nn] = x + y;
					x = f[i - j][mm - 1][nn - k];
					while (x != -1 && x + calc(j, k) < f[i][mm][nn]) {
						y = calc(j, k);
						if (x + y >= f[i][mm][nn]) break;
						f[i][mm][nn] = x + y;
						k++;
						if (k > nn) break;
						x = f[i - j][mm - 1][nn - k];
					}
				}
			}
		}
	}
	fout << setiosflags(ios::fixed) << setprecision(1) << f[100][m][n] << endl;
	return 0;
}
