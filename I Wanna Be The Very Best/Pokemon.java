import java.lang.String;
import java.lang.Long;

public class Pokemon {
    //Initializing variables; stores the health, attack and defense value of a Pokemon
    private Long health, attack, defense;

    //Workhorse Constructor
    public Pokemon(Long attack, Long defense, Long health) {
        this.health = health;
        this.attack = attack;
        this.defense = defense;
    }

    //Returrns health
    public Long getHealth() {
        return health;
    }

    //Returrns attack
    public Long getAttack() {
        return attack;
    }

    //Returns defense
    public Long getDefense() {
        return defense;
    }

    //Writes all of the date in the object in a string and returns it
    @Override
    public String toString() {
        return attack + " " + defense + " " + health;
    }

    //Checks if the two Pokemon objects are the same
    @Override
    public boolean equals(Object obj) {
        if(this == (Pokemon) obj)
            return true;
        
        if(obj instanceof Pokemon) {
            Pokemon p = (Pokemon) obj;

            return (this.health.equals(p.getHealth())) && 
                   (this.attack.equals(p.getAttack())) && 
                   (this.defense.equals(p.getDefense()));
        }

        return false;
    }
}