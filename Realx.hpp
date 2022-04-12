#include <iostream>
using namespace std;
template <typename i_t, typename f_t>
class realx {
	friend realx;
	friend std::ostream;
public:
	realx() = default;
	realx(const realx<i_t, f_t>&) = default;
	realx(const i_t& n) : num(n) { };
	inline operator i_t() const { return num; };
	inline auto& operator++() { num++; return *this; };
	inline auto& operator--() { num--; return *this; };
	inline realx operator+(const i_t& v) const { auto t = *this; t.num += v; return t; };
	inline realx operator-(const i_t& v) const { auto t = *this; t.num -= v; return t; };
	inline realx operator+(const realx<i_t, f_t>& other) const {
		auto t = *this;
		t.num += other.num;
		if (t.payda == other.payda)
			t.pay += other.pay;
		else {
			t.pay *= other.payda;
			const auto& t_pay = other.pay * t.payda;
			t.payda = other.payda * t.payda;
			t.pay += t_pay;
		};
		t.sadelestir();
		return t;
	};
	inline realx operator-(const realx<i_t, f_t>& other) const {
		auto t = *this;
		t.num -= other.num;
		if (t.payda == other.payda) {
			if (t.pay > other.pay)
				t.pay -= other.pay;
			else {
				t.pay = t.payda - (other.pay - t.pay);
				t.num--;
			};
		}
		else {
			t.pay *= other.payda;
			const auto& t_pay = other.pay * t.payda;
			t.payda = other.payda * t.payda;
			if (t.pay > other.pay)
				t.pay -= t_pay;
			else {
				t.pay = t.payda - (other.pay - t.pay);
				t.num--;
			};
		};
		t.sadelestir();
		return t;
	};
	inline realx operator/(const i_t& v) const {
		auto t = *this;
		const auto& kalan = t.num % v;
		t.num /= v;
		if (kalan != 0) {
			t.pay *= v;
			const auto& t_pay = kalan * t.payda;
			t.payda = v * t.payda;
			t.pay += t_pay;
		}
		else
			t.payda *= v;
		t.sadelestir();
		return t;
	};
	inline realx operator*(const i_t& v) const {
		auto t = *this;
		t.num *= v;
		t.pay *= v;
		t.sadelestir();
		return t;
	};
	inline auto& operator+=(const i_t& v) { num += v; return *this; };
	inline auto& operator-=(const i_t& v) { num -= v; return *this; };
	inline auto& operator/=(const i_t& v) {
		const auto& kalan = num % v;
		num /= v;
		if (kalan != 0) {
			pay *= v;
			const auto& t_pay = kalan * payda;
			payda = v * payda;
			pay += t_pay;
		}
		else
			payda *= v;
		sadelestir();
		return *this;
	};
	inline auto& operator*=(const i_t& v) {
		num *= v;
		pay *= v;
		sadelestir();
		return *this;
	};
	inline auto& operator+=(const realx<i_t, f_t>& other) {
		num += other.num;
		if (payda == other.payda)
			pay += other.pay;
		else {
			pay *= other.payda;
			const auto& t_pay = other.pay * payda;
			payda = other.payda * payda;
			pay += t_pay;
		};
		sadelestir();
		return *this;
	};
	inline auto& operator-=(const realx<i_t, f_t>& other) {
		num -= other.num;
		if (payda == other.payda) {
			if (pay > other.pay)
				pay -= other.pay;
			else {
				pay = payda - (other.pay - pay);
				num--;
			};
		}
		else {
			pay *= other.payda;
			const auto& t_pay = other.pay * payda;
			payda = other.payda * payda;
			if (pay > other.pay)
				pay -= t_pay;
			else {
				pay = payda - (other.pay - pay);
				num--;
			};
		};
		sadelestir();
		return *this;
	};
	friend std::ostream& operator<<(std::ostream& os, const realx<i_t, f_t>& v) {
		if (v.pay == 0)
			return os << v.num << ".0";
		else {
			os << v.num << '.';
			auto pay = v.pay;
			auto payda = v.payda;
			pay *= 10;
			f_t _kalan, __kalan, ___kalan = 0;
			bool first_digit = false;
			do {
				_kalan = pay % payda;
				if (!first_digit) ___kalan = _kalan;
				os << pay / payda;
				pay = pay % payda;
				pay *= 10;
				__kalan = pay % payda;
				first_digit = true;
			} while(__kalan != 0 and _kalan != __kalan and __kalan != ___kalan);
			if (__kalan == ___kalan and __kalan != 0)
				os << "..";
			return os;
		};
	};
private:
	void sadelestir() {
		if (pay == payda) {
			pay = 0;
			payda = 1;
			num++;
		}
		else {
			if (pay != 0 and payda % pay == 0) {
				pay = 1;
				payda = payda / pay;
			}
			else if (pay > payda) {
				const auto& kalan = pay % payda;
				const auto& t = pay / payda;
				if (kalan == 0) {
					pay = 0;
					payda = 1;
				}
				else {
					pay = kalan;
				};
				num += t;
			};
		};
	};
	i_t num = 0;
	f_t pay = 0, payda = 1;
};
using real = realx<int, unsigned short>;
