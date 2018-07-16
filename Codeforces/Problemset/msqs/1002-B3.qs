namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;

	operation Solve (qs: Qubit[]) : Int
	{
		body
		{
			ApplyToEach(H, qs);
			return ResultAsInt([M(qs[1]); M(qs[0])]);
		}
	}
}
