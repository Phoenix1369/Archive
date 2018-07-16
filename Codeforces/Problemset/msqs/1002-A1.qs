namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;

	operation Solve (qs: Qubit[]) : ()
	{
		body
		{
			let n = Length(qs);
			for (i in 0..(n-1))
			{
				H(qs[i]);
			}
		}
	}
}
