namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;

	operation Solve (qs: Qubit[], bits: Bool[]) : ()
	{
		body
		{
			H(qs[0]);
			let n = Length(qs);
			for (i in 1..(n-1))
			{
				if (bits[i])
				{
					CNOT(qs[0], qs[i]);
				}
			}
		}
	}
}
