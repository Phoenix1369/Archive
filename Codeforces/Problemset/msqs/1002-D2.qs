namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;

	operation Solve (x: Qubit[], y: Qubit, b: Int[]) : ()
	{
		body
		{
			let n = Length(x);
			for (i in 0..(n-1))
			{
				if (b[i] == 0)
				{
					X(x[i]);
					CNOT(x[i], y);
					X(x[i]);
				}
				else
				{
					CNOT(x[i], y);
				}
			}
		}
	}
}
