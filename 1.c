#include <stddef.h>

void lt(const int* src1, size_t step1, const int* src2, size_t step2, unsigned char* dst, size_t step3,
			   size_t width, size_t height) {
	size_t width_step = 4;
	for (; height--; src1 += step1, src2 += step2, dst += step3) {
		for (size_t i = 0; i < width - width_step; i += width_step) {
			for (size_t j = 0; j < width_step; ++j) {
				(dst + i)[j] = (src1 + i)[j] < (src2 + i)[j] ? 255 : 0;
			}
		}
		for (size_t i = width - width_step; i < width; ++i) {
			dst[i] = src1[i] < src2[i] ? 255 : 0;
		}
	}
}
