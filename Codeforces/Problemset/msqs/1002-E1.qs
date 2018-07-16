namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;

	operation Solve (N: Int, Uf: ((Qubit[], Qubit) => ())) : Int[]
	{
		body
		{	// Bernstein-Vazirani
			mutable b = new Int[N];
			using (qs = Qubit[N+1])
			{
				X(qs[N]);
				ApplyToEach(H, qs);
				Uf(qs[0..(N-1)], qs[N]);
				ApplyToEach(H, qs[0..(N-1)]);
				for (i in 0..(N-1))
				{
					set b[i] = ResultAsInt([M(qs[i])]);
				}
				ResetAll(qs);
			}
			return b;
		}
	}
}
