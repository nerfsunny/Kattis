using System;
using System.IO;
using System.Collections.Generic;

public class readMeScript {
	public static void Main(string[] args) {
		string line;
		string header;
		List<string> lines = new List<string>();

		System.IO.StreamReader inputFile = new System.IO.StreamReader("data.txt");
		header = inputFile.ReadLine();

		while((line = inputFile.ReadLine()) != null)
			lines.Add(line);

		inputFile.Close();

		System.IO.StreamWriter outputFile = new System.IO.StreamWriter("ReadMe.md");

		outputFile.WriteLine("This repository contains my attempt at solving programming problems I find online. Below there is a table that contains the problem name, the status of the problem, where the problem was found and what language(s) it is completed in.\n");
		outputFile.WriteLine(header);
		outputFile.WriteLine("------------ | ------------ | ------------ | ------------");

		//Sorts the lines in alphabetical order
		lines.Sort();

		foreach(string x in lines)
			outputFile.WriteLine(x);

		outputFile.Close();
	}
}