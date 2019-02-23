// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
	while (isBadVersion(n--));
	return n + 2;
}

