#include <omp.h>
#include <string.h>

#define N 128

int A[N][N], B[N][N], C[N][N];

int main(int argc, char const *argv[])
{
	int i=0, j=0, k=0;

	memset(A, 0, N*N*sizeof(int));
	memset(B, 0, N*N*sizeof(int));
	memset(C, 0, N*N*sizeof(int));

	#pragma omp parallel for
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			for(k=0; k<N; k++) {
				C[i][j] += A[i][k]*B[k][j];
			}
		}
	}

	return 0;
}
