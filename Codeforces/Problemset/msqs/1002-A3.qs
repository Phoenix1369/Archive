namespace Solution
{
	open Microsoft.Quantum.Canon;
	open Microsoft.Quantum.Primitive;

	operation Solve (qs: Qubit[], bits0: Bool[], bits1: Bool[]) : ()
	{
		body
		{
			let n = Length(qs);
			mutable p = -1;
			repeat
			{
				set p = p + 1;
			}
			until (bits0[p] != bits1[p])
			fixup { }
			
			H(qs[p]);
			for (i in 0..(n-1))
			{
				if (bits0[i] == bits1[i])
				{
					if (bits0[i])
					{
						X(qs[i]);
					}
				}
				elif (i != p)
				{
					if (bits0[i] != bits0[p])
					{
						X(qs[i]);
					}
					CNOT(qs[p], qs[i]);
				}
			}
		}
	}
}
