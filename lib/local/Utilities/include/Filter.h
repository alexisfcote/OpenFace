#ifndef __FILTER__
#define __FILTER__


namespace filter {
	class Filter
	{

	public:
		Filter(float alpha);
		Filter(float alpha, float z);
		~Filter();

		float filt(float val);

		float z;
		float alpha;
	};
}
#endif // __FILTER__