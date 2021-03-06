#pragma once
#include <iostream>
#include <string>

namespace BF
{
	namespace Math
	{
		template<class T>
		class Vector4
		{
			public:
				T x;
				T y;
				T z;
				T w;

				Vector4();
				Vector4(T value);
				Vector4(T x, T y, T z, T w);
				~Vector4();

				T Dot(const Vector4& vector) const;
				T Distance(const Vector4& vector) const;
				T Magnitude() const;
				Vector4 Direction(const Vector4& vector) const;
				Vector4 Normalize() const;
				Vector4 Center() const;
				Vector4 Min();
				Vector4 Max();

				Vector4& operator+=(const Vector4& right);
				Vector4& operator-=(const Vector4& right);
				Vector4& operator*=(const Vector4& right);
				Vector4& operator/=(const Vector4& right);

				bool operator>(const Vector4& right);
				bool operator>=(const Vector4& right);
				bool operator<(const Vector4& right);
				bool operator<=(const Vector4& right);

				bool operator==(const Vector4& right);
				bool operator!=(const Vector4& right);

				friend std::string operator+(const std::string& left, const Vector4& right) { return left + "{" + std::to_string(right.x) + ", " + std::to_string(right.y) + ", " + std::to_string(right.z) + ", " + std::to_string(right.w) + "}"; }
				friend std::string operator+(const Vector4& left, const std::string& right) { return "{" + std::to_string(left.x) + ", " + std::to_string(left.y) + ", " + std::to_string(left.z) + ", " + std::to_string(left.w) + "}" + right; }

				friend Vector4 operator+(const Vector4& left, const Vector4& right) { return Vector4(left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w); }
				friend Vector4 operator-(const Vector4& left, const Vector4& right) { return Vector4(left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w); }
				friend Vector4 operator*(const Vector4& left, const Vector4& right) { return Vector4(left.x * right.x, left.y * right.y, left.z * right.z, left.w * right.w); }
				friend Vector4 operator/(const Vector4& left, const Vector4& right) { return Vector4(left.x / right.x, left.y / right.y, left.z / right.z, left.w / right.w); }

				friend std::ostream& operator<<(std::ostream& os, const Vector4& vector) { return os << "{" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << "}"; }
		};

#include "Vector4.inl"

		typedef Vector4<int> Vector4i;
		typedef Vector4<float> Vector4f;
	}
}