
#include "Violet.h"

static std::vector<Violet::Vec3d> precisionCube_plsRewriteMEEeeeSoonxoxo(double radius, int divisions) {
	std::vector<Violet::Vec3d> cubePoints;
	double stride = (2.0 * radius) / ((double)divisions + 1.0);
	std::vector<Violet::Vec3d> facePoints;
	for (size_t side = 0; side < 6; side++) {
		facePoints.clear();
		for (size_t i = 0; i < divisions + 1; i++) {
			for (size_t j = 0; j < divisions + 1; j++) {
				double x = -radius + (stride * (double)i);
				double y = -radius + (stride * (double)j);
				facePoints.push_back({ x,          y,          0.0 });
				facePoints.push_back({ x + stride, y,          0.0 });
				facePoints.push_back({ x,          y + stride, 0.0 });
				facePoints.push_back({ x + stride, y,          0.0 });
				facePoints.push_back({ x + stride, y + stride, 0.0 });
				facePoints.push_back({ x,          y + stride, 0.0 });
			}
		}
		if (side == 0) {
			for (Violet::Vec3d& point : facePoints) {
				point.z += radius;
				cubePoints.push_back(point);
			}
		}
		if (side == 1) {
			for (Violet::Vec3d& point : facePoints) {
				point.rotate(Violet::Vec3d(1.0, 0.0, 0.0), Violet::Pi64 / 2.0);
				point.y += radius;
				cubePoints.push_back(point);
			}
		}
		if (side == 2) {
			for (Violet::Vec3d& point : facePoints) {
				point.rotate(Violet::Vec3d(1.0, 0.0, 0.0), Violet::Pi64);
				point.z -= radius;
				cubePoints.push_back(point);
			}
		}
		if (side == 3) {
			for (Violet::Vec3d& point : facePoints) {
				point.rotate(Violet::Vec3d(1.0, 0.0, 0.0), -Violet::Pi64 / 2.0);
				point.y -= radius;
				cubePoints.push_back(point);
			}
		}
		if (side == 4) {
			for (Violet::Vec3d& point : facePoints) {
				point.rotate(Violet::Vec3d(0.0, 1.0, 0.0), Violet::Pi64 / 2.0);
				point.x += radius;
				cubePoints.push_back(point);
			}
		}
		if (side == 5) {
			for (Violet::Vec3d& point : facePoints) {
				point.rotate(Violet::Vec3d(0.0, 1.0, 0.0), -Violet::Pi64 / 2.0);
				point.x -= radius;
				cubePoints.push_back(point);
			}
		}
	}
	return cubePoints;
}

void Violet::Mesh::cube(double radius, int divisions) {
	vertices.clear();
	std::vector<Vec3d> cubePoints = precisionCube_plsRewriteMEEeeeSoonxoxo(radius, divisions);
	for (const Vec3d& point : cubePoints) {
		vertices.push_back({ Vec3f(point), Color::random() });
	}
}

void Violet::Mesh::sphere(double radius, int divisions) {
	vertices.clear();
	std::vector<Vec3d> cubePoints = precisionCube_plsRewriteMEEeeeSoonxoxo(1.0, divisions);
	for (Vec3d point : cubePoints) {
		point.normalize();
		point = point * radius;
		vertices.push_back({ Vec3f(point), Color::random() });
	}
}

