namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;

	operation Solve (N: Int, Uf: ((Qubit[], Qubit) => ())) : Bool
	{
		body
		{
			mutable res = true;
			using (q = Qubit[N+1])
			{
				X(q[N]);
				ApplyToEach(H, q);
				Uf(q[0..(N-1)], q[N]);
				ApplyToEach(H, q[0..(N-1)]);

				for (i in 0..(N-1))
				{
					if (M(q[i]) != Zero)
					{
						set res = false;
					}
				}
				ResetAll(q);
			}
			return res;
		}
	}
}
