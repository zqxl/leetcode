// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
	while (isBadVersion(n--));
	return n + 2;
}

// ¶þ·Ö²éÕÒ
int firstBadVersion(int n) {
	long int low = 0, high = n, mid = 0;
	while (high >= low) {
		mid = (low + high) / 2;
		if (!isBadVersion(mid)) {
			if (isBadVersion(mid + 1)) {
				return mid + 1;
			}
			else {
				low = mid + 1;
			}
		}
		else {
			high = mid;
		}
	}
	return mid + 1;
}

