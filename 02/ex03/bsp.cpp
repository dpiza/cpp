#include "bsp.h"

static Fixed scale(Point &p, Point &q) {
	Fixed s((p.getX() * q.getX()) + (p.getY() * q.getY()));
	return s;
}

static Point vector(Point const a, Point const b) {
	Fixed x = (b.getX() - a.getX());
	Fixed y = (b.getY() - a.getY());
	float xf = x.toFloat();
	float yf = y.toFloat();
	Point p(xf, yf);

	return (p);
}

bool bsp(Point const a, Point const b, Point const c, Point const p) {
	Point v0 = vector(a, b);
	Point v1 = vector(a, c);
	Point v2 = vector(a, p);

	Fixed p00 = scale(v0, v0);
	Fixed p11 = scale(v1, v1);
	Fixed p01 = scale(v0, v1);
	Fixed p02 = scale(v0, v2);
	Fixed p12 = scale(v1, v2);

	Fixed div = p11 * p00 - p01 * p01;
	Fixed u = (p11 * p02 - p01 * p12) / div;
	Fixed v = (p00 * p12 - p01 * p02) / div;

	if ((u >= 0) && (v >= 0) && (u + v < 1)) {
		return true;
	} else {
		return false;
	}
}
