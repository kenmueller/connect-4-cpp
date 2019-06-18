#define GRID_SIZE 4
#define WIN_LAYOUTS_COUNT 10
#define A true
#define B false

const bool winLayouts[WIN_LAYOUTS_COUNT][GRID_SIZE][GRID_SIZE] = {
	{
		B, B, B, B,
		B, B, B, B,
		B, B, B, B,
		A, A, A, A
	},
	{
		B, B, B, B,
		B, B, B, B,
		A, A, A, A,
		B, B, B, B
	},
	{
		B, B, B, B,
		A, A, A, A,
		B, B, B, B,
		B, B, B, B
	},
	{
		A, A, A, A,
		B, B, B, B,
		B, B, B, B,
		B, B, B, B
	},
	{
		A, B, B, B,
		A, B, B, B,
		A, B, B, B,
		A, B, B, B
	},
	{
		B, A, B, B,
		B, A, B, B,
		B, A, B, B,
		B, A, B, B
	},
	{
		B, B, A, B,
		B, B, A, B,
		B, B, A, B,
		B, B, A, B
	},
	{
		B, B, B, A,
		B, B, B, A,
		B, B, B, A,
		B, B, B, A
	},
	{
		A, B, B, B,
		B, A, B, B,
		B, B, A, B,
		B, B, B, A
	},
	{
		B, B, B, A,
		B, B, A, B,
		B, A, B, B,
		A, B, B, B
	}
};