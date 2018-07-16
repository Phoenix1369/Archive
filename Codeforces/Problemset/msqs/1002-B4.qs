namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;

	operation Solve (qs: Qubit[]) : Int
	{
		body
		{
			// S[0] = 0 -> [0,-1], -1 -> [0,1]
			// S[1] = -0 ->[0,-1], -1 -> [0,1]
			// S[2] = -0 ->[0,1], 1 -> [0,-1]
			// S[3] = -0 ->[0,1],-1 -> [0,-1]
			// Pauli Z gate for negative signs (ignored)
			//   ie. M(1) == M(-1) == One
			// Operations are unitary (reverse to undo)

			H(qs[1]);
			CNOT(qs[0], qs[1]);
			X(qs[1]);

			H(qs[0]);
			X(qs[0]);

			return ResultAsInt([M(qs[0]); M(qs[1])]);
		}
	}
}
