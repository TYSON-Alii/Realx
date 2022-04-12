## Realx
Rasyonel kayan noktalı sayı sistemi.
```cpp
auto main() -> int {
	cout << setprecision(50);
	real num = 1000;
	cout << "real: 1000 / 17 = " << num / 17 << " size of: " << sizeof(num) << '\n';
	float num2 = 1000.f;
	cout << "f32: 1000 / 17 = " << num2 / 17 << " size of: " << sizeof(num2) << '\n';
	double num3 = 1000.0;
	cout << "f64: 1000 / 17 = " << num3 / 17 << " size of: " << sizeof(num3) << '\n';
};
/*
# OUTPUT:
real: 1000 / 17 = 58.8235294117647058.. size of: 8 // correct
f32: 1000 / 17 = 58.823528289794921875 size of: 4 // wrong after a while
f64: 1000 / 17 = 58.82352941176470295658873510546982288360595703125 size of: 8 // wrong after a while
*/
```
