namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;

	operation Solve (qs: Qubit[]) : Int
	{
		body
		{
			CNOT(qs[0], qs[1]);
			H(qs[0]);
			return ResultAsInt([M(qs[0]); M(qs[1])]);
		}
	}
}
