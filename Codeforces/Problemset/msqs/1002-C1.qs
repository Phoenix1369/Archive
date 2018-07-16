namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;

	open Microsoft.Quantum.Extensions.Math;

	operation Solve (q: Qubit) : Int
	{
		body
		{	// Rotation by pi/8
			Ry(PI() / 4.0, q);
			return ResultAsInt([M(q)]);
		}
	}
}
