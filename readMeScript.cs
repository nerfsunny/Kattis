using System;
using System.IO;
using System.Collections.Generic;

public class readMeScript {
	public static Dictionary<int, List<string>> populate() {
		Dictionary<int, List<string>> table = new Dictionary<int, List<string>>();

		List<string> sources = new List<string>() {
			"Kattis",
			"Reddit",
			"HackerRank",
			"Leetcode",
			"Project Euler"
		};

		List<string> status = new List<string>() {
			"Planned",
			"In Progress",
			"Completed",
			"Dropped",
		};

		List<string> languages = new List<string>() {
			"C++",
			"Java",
			"Python",
			"C#",
			"Swift",
			"Haskell",
			"Ruby",
			"Scala",
			"N/A"
		};

		table[1] = sources;
		table[2] = status;
		table[3] = languages;

		return table;
	}

	public static void Main(string[] args) {
		string line;
		string header;
		List<string> lines = new List<string>();

		Dictionary<int, List<string>> table = populate();

		System.IO.StreamReader inputFile = new System.IO.StreamReader("data.txt");
		header = inputFile.ReadLine();

		while((line = inputFile.ReadLine()) != null)
			lines.Add(line);

		inputFile.Close();

		System.IO.StreamWriter outputFile = new System.IO.StreamWriter("ReadMe.md");

		outputFile.WriteLine("## Description");
		outputFile.WriteLine("This repository contains my attempt at solving programming problems I find online. Below is a table that contains the problem name, the status of the problem, where the problem was found and what language(s) it is completed in.\n");

		outputFile.WriteLine("## Complete Problem List");
		outputFile.WriteLine(header);
		outputFile.Write("------------ | ------------ | ------------ | ------------");

		//Sorts the lines in alphabetical order
		lines.Sort();

		foreach(string x in lines)
			outputFile.WriteLine(x);

		outputFile.Write("\n");
		outputFile.WriteLine("## Stats");

		outputFile.WriteLine("Language | Number of Problems");
		outputFile.WriteLine("--- | ---");

		int counter = 0;

		foreach(string language in table[3]) {
			foreach(string s in lines) 
				if(s.Contains(language))
					counter++;

			if(counter != 0 & language != "N/A")
				outputFile.WriteLine(language + " | " + counter);
			
			counter = 0;
		}

		outputFile.Write("\n");

		outputFile.WriteLine("Source | Number of Problems");
		outputFile.WriteLine("--- | ---");

		foreach(string source in table[1]) {
			foreach(string s in lines) 
				if(s.Contains(source))
					counter++;

			if(counter != 0)
				outputFile.WriteLine(source + " | " + counter);
			
			counter = 0;
		}

		outputFile.Write("\n");

		outputFile.WriteLine("Status | Number of Problems");
		outputFile.WriteLine("--- | ---");

		foreach(string status in table[2]) {
			foreach(string s in lines) 
				if(s.Contains(status))
					counter++;

			if(counter != 0)
				outputFile.WriteLine(status + " | " + counter);
			
			counter = 0;
		}

		outputFile.Close();
	}
}