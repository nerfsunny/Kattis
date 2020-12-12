import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;
import java.lang.String;

//Comparator that overrides default one and sorts Pokemon by their health
class sortByHealth implements Comparator<Pokemon> {
    @Override
    public int compare(Pokemon p1, Pokemon p2) {
        return p1.getHealth().compareTo(p2.getHealth());
    }
}

//Comparator that overrides default one and sorts Pokemon by their attack
class sortByAttack implements Comparator<Pokemon> {
    @Override
    public int compare(Pokemon p1, Pokemon p2) {
        return p1.getAttack().compareTo(p2.getAttack());
    }
}

//Comparator that overrides default one and sorts Pokemon by their defense
class sortByDefense implements Comparator<Pokemon> {
    @Override
    public int compare(Pokemon p1, Pokemon p2) {
        return p1.getDefense().compareTo(p2.getDefense());
    }
}

public class iWanna {
    //Goes through pokemonList from [0, maximumPokemon-1] and stores a copy in pokemonTeeam if one does not already exist
    public static void topPokemon(ArrayList<Pokemon> pokemonList, ArrayList<Pokemon> pokemonTeam, int maximumPokemon) {
        //For-loop that grabs the top maximumPokemon in either health, attack, or defense (depending on how the given pokemonList was sorted)
        for(int i = 0; i < maximumPokemon; i++)
            //Checks if Pokemon is already in the list; if it is not, then it stores it in pokemonTeam
            if(!pokemonTeam.contains(pokemonList.get(i)))
                pokemonTeam.add(pokemonList.get(i));
    }
    public static void main(String[] args) {
        //Initializing Scanner object
        Scanner scan = new Scanner(System.in);

        /*Initializing variables
          numberOfPokemon, stores the totak number of pokemon the user can pick from
          maximumPokemon, stores the number of pokemon that the user wants to pick the best of, given a stat (health, attack, defense)
        */
        int numberOfPokemon = scan.nextInt(), maximumPokemon = scan.nextInt();

        /*Initializing containers
          pokemonList stores all of the Pokemon
          pokemonTeam stores the best Pokemon(s) in a given state
        */
        ArrayList<Pokemon> pokemonList = new ArrayList<Pokemon>(numberOfPokemon), pokemonTeam = new ArrayList<Pokemon>();

        //For-loop that iterates through the inputs, creates a Pokemon, and stores it in pokemonList
        for(int i = 0; i < numberOfPokemon; i++) 
            pokemonList.add(new Pokemon(scan.nextLong(), scan.nextLong(), scan.nextLong()));
        
        //Closing Scanner
        scan.close();

        //Sorts pokemonList in descending order by health stat
        Collections.sort(pokemonList, new sortByHealth().reversed());

        //Gets the top maximumPokemon in regards to the health stat and stores it in pokemonTeam
        topPokemon(pokemonList, pokemonTeam, maximumPokemon);

        //Sorts pokemonList in descending order by attack stat
        Collections.sort(pokemonList, new sortByAttack().reversed());

        //Gets the top maximumPokemon in regards to the attack stat and stores it in pokemonTeam
        topPokemon(pokemonList, pokemonTeam, maximumPokemon);
        
        //Sorts pokemonList in descending order by defense stat
        Collections.sort(pokemonList, new sortByDefense().reversed());

        //Gets the top maximumPokemon in regards to the defense stat and stores it in pokemonTeam
        topPokemon(pokemonList, pokemonTeam, maximumPokemon);

        //Outputs the number of unique Pokemon that are in the top numberOfPokemon for health, attack and/or defense
        System.out.println(pokemonTeam.size());
    }
}