SUB Addons_Setup

/Return

SUB Addons_Background_Events
    /doevents Ancients70
    /doevents Ancients65
    /doevents SkillCheck
    /doevents CheckHaste
    /doevents FindID
/return

|----------------------------------------------------|
|Checks for ancients in book and books and Ancient Runes in bags.
|/useage /bc Ancients70
|This IS valid for Use on PEQ
|----------------------------------------------------|
#EVENT Ancients70 "<#*#> Ancients70"
Sub EVENT_Ancients70(line)
    /echo "Ancients"
	/cleanup
	/cleanup
    /declare Ancients int local 0
	/declare Spellone String local
	/declare Spelltwo String local
    /if (${Select[${Me.Class.ShortName},BER,MNK,ROG,WAR]}>0) /varset Ancients 0
    /if (${Select[${Me.Class.ShortName},BRD,BST,PAL,RNG,SHD]}>0) /varset Ancients 1
	/if (${Select[${Me.Class.ShortName},CLR,DRU,ENC,MAG,NEC,SHM,WIZ]}>0) /varset Ancients 2
    /declare SpellName string local
	/declare SpellTwoName string local
	/declare SpellNotFound int local 0
	
	/if (${Me.Class.ShortName.Equal[BRD]}) /varset SpellName "Ancient: Call of Power"
	
	/if (${Me.Class.ShortName.Equal[BST]}) /varset SpellName "Ancient: Savage Ice"
	
	/if (${Me.Class.ShortName.Equal[CLR]}) /varset SpellName "Ancient: Hallowed Light"
	/if (${Me.Class.ShortName.Equal[CLR]}) /varset SpellTwoName "Ancient: Pious Conscience"
	
	/if (${Me.Class.ShortName.Equal[DRU]}) /varset SpellName "Ancient: Chlorobon"
	/if (${Me.Class.ShortName.Equal[DRU]}) /varset SpellTwoName "Ancient: Glacier Frost"
	
	/if (${Me.Class.ShortName.Equal[ENC]}) /varset SpellName "Ancient: Voice of Muram"
	/if (${Me.Class.ShortName.Equal[ENC]}) /varset SpellTwoName "Ancient: Neurosis"
	
	/if (${Me.Class.ShortName.Equal[MAG]}) /varset SpellName "Ancient: Nova Strike"
	/if (${Me.Class.ShortName.Equal[MAG]}) /varset SpellTwoName "Ancient: Veil of Pyrilonus"
	
	/if (${Me.Class.ShortName.Equal[NEC]}) /varset SpellName "Ancient: Touch of Orshalik"
	/if (${Me.Class.ShortName.Equal[NEC]}) /varset SpellTwoName "Ancient: Curse of Mori"
	
	/if (${Me.Class.ShortName.Equal[PAL]}) /varset SpellName "Ancient: Force of Jeron"
	
	/if (${Me.Class.ShortName.Equal[RNG]}) /varset SpellName "Ancient: North Wind"
	
	/if (${Me.Class.ShortName.Equal[SHD]}) /varset SpellName "Ancient: Bite of Muram"
	
	/if (${Me.Class.ShortName.Equal[SHM]}) /varset SpellName "Ancient: Wilslik's Mending"
	/if (${Me.Class.ShortName.Equal[SHM]}) /varset SpellTwoName "Ancient: Ancestral Calling"
	
	/if (${Me.Class.ShortName.Equal[WIZ]}) /varset SpellName "Ancient: Core Fire"
	/if (${Me.Class.ShortName.Equal[WIZ]}) /varset SpellTwoName "Ancient: Spear of Gelaqua"
    
	|/if (${Ancients}==0) /bc [+T+] There are no ancients for my class ${Me.Class}
	/if (${Ancients}==0) /echo There are no ancients for my class ${Me.Class}
	
	|/if (${Ancients}==1) /bc [+w+] I will be Seeking: ${SpellName}
	|/if (${Ancients}==1) /echo I will be Seeking: ${SpellName}
	
	|/if (${Ancients}==2) /bc [+w+] I will be Seeking: ${SpellName} ${SpellTwoName}
	|/if (${Ancients}==2) /echo I will be Seeking: ${SpellName} ${SpellTwoName}	
	
	/if (${Ancients}>0) {
		/echo Seeking: ${SpellName}
		|/if (${Me.CombatAbility[${SpellName}]}) /bc [+T+] I have tome: ${SpellName}
		/if (${Me.CombatAbility[${SpellName}]}) /echo I have tome: ${SpellName}
		
		|/if (${Me.Book[${SpellName}]}) /bc [+T+] I have in book: ${SpellName}
		/if (${Me.Book[${SpellName}]}) /echo I have in book: ${SpellName}
		
		|/if (${FindItemCount[${SpellName}]}) /bc [+T+] I have the spell in bag : ${SpellName}
		/if (${FindItemCount[${SpellName}]}) /echo I have the spell in bag : ${SpellName}
		
		/if (!${Me.CombatAbility[${SpellName}]} && !${Me.Book[${SpellName}]} && !${FindItemCount[${SpellName}]}) {
				|/bc [+Y+] Did not Find: ${SpellName}
				/echo Did not Find: ${SpellName}
				/varset SpellNotFound 1
			}
	}
	/if (${Ancients}==2) {
		/echo Seeking: ${SpellTwoName}
		|/if (${Me.CombatAbility[${SpellTwoName}]}) /bc [+T+] I have tome: ${SpellTwoName}
		/if (${Me.CombatAbility[${SpellTwoName}]}) /echo I have tome: ${SpellTwoName}
		
		|/if (${Me.Book[${SpellTwoName}]}) /bc [+T+] I have in book: ${SpellTwoName}
		/if (${Me.Book[${SpellTwoName}]}) /echo I have in book: ${SpellTwoName}
		
		|/if (${FindItemCount[${SpellTwoName}]}) /bc [+T+] I have the spell in bag : ${SpellTwoName}
		/if (${FindItemCount[${SpellTwoName}]}) /echo I have the spell in bag : ${SpellTwoName}
		
		/if (!${Me.CombatAbility[${SpellTwoName}]} && !${Me.Book[${SpellTwoName}]} && !${FindItemCount[${SpellTwoName}]}) {
				|/bc [+Y+] Did not Find: ${SpellTwoName}
				/echo Did not Find: ${SpellTwoName}
				/if (${SpellNotFound}) /varset SpellNotFound 2
				/if (!${SpellNotFound}) /varset SpellNotFound 1
			}
	}
	/if (!${SpellNotFound} && ${FindItemCount[Ancient Muramite Rune]}) /bc [+o+] I have [+p+]${FindItemCount[Ancient Muramite Rune]} [+y+] Ancient Muramite Runes [+o+] in bag. >> DESTROY THEM ALL<<
	/delay 1s
	/if (${SpellNotFound} && ${SpellNotFound}>${FindItemCount[Ancient Muramite Rune]}) /bc [+R+] I have [+p+]${FindItemCount[Ancient Muramite Rune]} of ${SpellNotFound} [+y+] Ancient Muramite Runes [+R+] in bag. [+Y+]>[+R+]>[+Y+]>[+R+]>[+Y+] I NEED MORE [+R+]<[+Y+]<[+R+]<[+Y+]<
	/delay 1s
	/if (${SpellNotFound} && ${SpellNotFound}==${FindItemCount[Ancient Muramite Rune]}) /bc [+O+]I have [+p+]${FindItemCount[Ancient Muramite Rune]} of ${SpellNotFound} [+y+] Ancient Muramite Runes [+O+] in bag. >> GO TURNIN!<<
	/delay 1s
	/if (${SpellNotFound} && ${SpellNotFound}<${FindItemCount[Ancient Muramite Rune]}) /bc [+g+] I have [+p+]${FindItemCount[Ancient Muramite Rune]} of ${SpellNotFound} [+y+] Ancient Muramite Runes [+g+] in bag. >> AFTER TURNINS, I HAVE EXTRA <<
	/delay 1s
	/if (!${SpellNotFound} && !${FindItemCount[Ancient Muramite Rune]}) /bc [+G+] PERFECT! I have all spells, no extra runes.
/return

|----------------------------------------------------|
|Checks for ancinets in book and books and Ancient Runes in bags.
|/useage /bc Ancients65
|This IS valid for Use on PEQ
|----------------------------------------------------|
#EVENT Ancients65 "<#*#> Ancients65"
Sub EVENT_Ancients65(line)
	/declare ChaosAncients int local 0
    /if (${Select[${Me.Class.ShortName},SHD,RNG,CLR,BRD,DRU,ENC,MAG,SHM,PAL,BST,NEC,WIZ]}>0) /varset ChaosAncients 1
	/if (${Select[${Me.Class.ShortName},WAR,ROG,BER,MNK]}>0) /varset ChaosAncients 1
    
	/declare SpellName string local
	/declare SpellNotFound int local 0
		/if (${Me.Class.ShortName.Equal[BRD]}) /varset SpellName "Ancient: Chaos Chant"
		/if (${Me.Class.ShortName.Equal[BST]}) /varset SpellName "Ancient: Frozen Chaos"
		/if (${Me.Class.ShortName.Equal[BER]}) /varset SpellName "Ancient: Cry of Chaos"
		/if (${Me.Class.ShortName.Equal[CLR]}) /varset SpellName "Ancient: Chaos Censure"
		/if (${Me.Class.ShortName.Equal[DRU]}) /varset SpellName "Ancient: Chaos Frost"
		/if (${Me.Class.ShortName.Equal[ENC]}) /varset SpellName "Ancient: Chaos Madness"
		/if (${Me.Class.ShortName.Equal[MAG]}) /varset SpellName "Ancient: Chaos Vortex"
		/if (${Me.Class.ShortName.Equal[MNK]}) /varset SpellName "Ancient: Phantom Chaos"
		/if (${Me.Class.ShortName.Equal[NEC]}) /varset SpellName "Ancient: Seduction of Chaos"
		/if (${Me.Class.ShortName.Equal[PAL]}) /varset SpellName "Ancient: Force of Chaos"
		/if (${Me.Class.ShortName.Equal[RNG]}) /varset SpellName "Ancient: Burning Chaos"
		/if (${Me.Class.ShortName.Equal[ROG]}) /varset SpellName "Ancient: Chaos Strike"
		/if (${Me.Class.ShortName.Equal[SHD]}) /varset SpellName "Ancient: Bite of Chaos"
		/if (${Me.Class.ShortName.Equal[SHM]}) /varset SpellName "Ancient: Chaotic Pain"
		/if (${Me.Class.ShortName.Equal[WAR]}) /varset SpellName "Ancient: Chaos Cry"
		/if (${Me.Class.ShortName.Equal[WIZ]}) /varset SpellName "Ancient: Strike of Chaos"
 
	/echo Seeking: ${SpellName}
	|CHECK TOMES
	|/if (${Me.CombatAbility[${SpellName}]}) /bc [+T+] I have tome: ${SpellName}
	/if (${Me.CombatAbility[${SpellName}]}) /echo I have tome: ${SpellName}
	|CHECK SPELLS	
	|/if (${Me.Book[${SpellName}]}) /bc [+T+] I have spell: ${SpellName}
	/if (${Me.Book[${SpellName}]}) /echo I have spell: ${SpellName}
	|CHECK BAGS
	|/if (${FindItemCount[${SpellName}]}) /bc [+T+] I have the in bag : ${SpellName}
	/if (${FindItemCount[${SpellName}]} || ${FindItemCount[Tome of ${SpellName}]}) /echo I have in bag : ${SpellName}
	|NOT FOUND COUNT
	/if (!${Me.CombatAbility[${SpellName}]} && !${Me.Book[${SpellName}]} && !${FindItemCount[${SpellName}]} && !${FindItemCount[${SpellName}]}) {
				|/bc [+Y+] Did not Find: ${SpellName}
				/echo Did not Find: ${SpellName}
				/varset SpellNotFound 1
			}
	|COUNT RUNES AND REPORT
	|DELAYS ADDED TO HELP GROUP RESULTS.
	/if (${SpellNotFound}==0 && ${FindItemCount[Chaos Rune]}) /bc [+o+] I have [+p+]${FindItemCount[Chaos Rune]} [+y+] Chaos Runes [+o+] in bag. >> DESTROY THEM ALL<<
	/delay 1s
	/if (${SpellNotFound}==0 && !${FindItemCount[Chaos Rune]}) /bc [+G+] PERFECT! I have all spells, no extra runes.
	/delay 1s
	/if (${SpellNotFound}>0 && ${SpellNotFound}>${FindItemCount[Chaos Rune]}) /bc [+R+] I have [+p+]${FindItemCount[Chaos Rune]} of ${SpellNotFound} [+y+] Chaos Runes [+R+] in bag. [+Y+]>[+R+]>[+Y+]>[+R+]>[+Y+] I NEED MORE [+R+]<[+Y+]<[+R+]<[+Y+]<
	/delay 1s
	/if (${SpellNotFound}>0 && ${SpellNotFound}==${FindItemCount[Chaos Rune]}) /bc [+O+]I have [+p+]${FindItemCount[Chaos Rune]} of ${SpellNotFound} [+y+] Chaos Runes [+O+] in bag. >> GO TURNIN!<<
	/delay 1s
	/if (${SpellNotFound}>0 && ${SpellNotFound}<${FindItemCount[Chaos Rune]}) /bc [+g+] I have [+p+]${FindItemCount[Chaos Rune]} of ${SpellNotFound} [+y+] Chaos Runes [+g+] in bag. >> EVEN AFTER TURNINS, HAVE EXTRA <<
/return

|----------------------------------------------------|
|-Checks status of all Skills
|/useage /bc SkillCheck #1#
|This IS valid for Use on PEQ
|----------------------------------------------------|
#EVENT SkillCheck "<#1#> SkillCheck #2#"
#EVENT SkillCheck "<#1#> CheckSkill #2#"
Sub EVENT_SkillCheck(line,ChatSender,SkillToCheck)
/echo Skill Checking for --> ${SkillToCheck} <--
  /if (!${checkEventArgs[${ChatSender},${line},U,${SkillToCheck}]}) /return
  /varset SkillToCheck ${c_eventArgData}
/if (${SkillToCheck.Equal[ALL]}) /bc TEST ALL
/if (${Skill[${SkillToCheck}].SkillCap}>0 && ${Me.Skill[${SkillToCheck}]}>0 && ${Me.Skill[${SkillToCheck}]}>${Skill[${SkillToCheck}].SkillCap}) /bc [+G+] ${SkillToCheck} MAXED
/if (${Skill[${SkillToCheck}].SkillCap}>0 && ${Me.Skill[${SkillToCheck}]}==${Skill[${SkillToCheck}].SkillCap}) /bc [+G+] ${SkillToCheck} MAXED
/if (${Skill[${SkillToCheck}].SkillCap}>0 && ${Me.Skill[${SkillToCheck}]}>0 && ${Me.Skill[${SkillToCheck}]}<${Skill[${SkillToCheck}].SkillCap}) {
	/delay 1s
	/bc [+Y+] ${SkillToCheck} :: ${Me.Skill[${SkillToCheck}]} of ${Skill[${SkillToCheck}].SkillCap}
	}
/if (${Skill[${SkillToCheck}].SkillCap}>0 && ${Me.Skill[${SkillToCheck}]}==0 && ${Me.Skill[${SkillToCheck}]}<${Skill[${SkillToCheck}].SkillCap}) {
	/delay 2s
	/bc [+R+] ${SkillToCheck} :: GOTO TRAINER:: ${Me.Skill[${SkillToCheck}]} of  ${Skill[${SkillToCheck}].SkillCap}
	}
/if (${Skill[${SkillToCheck}].SkillCap}==0 && ${Me.Skill[${SkillToCheck}]}>0) {
	/delay 2s
	/bc [+T+] ${SkillToCheck} ::${Me.Skill[${SkillToCheck}]}  - CAP INCORRECT
	}
/return

|------------------------------------------------------------|
|- Checks for Haste Spell and 225 Haste on Melee  on NetBots-|
|- Use, /bc Check Haste.                                -|
|------------------------------------------------------------|
#EVENT CheckHaste "<#1#> Check Haste"
SUB EVENT_CheckHaste(line, ChatSender)
/if (${Debug} || ${Debug_Basics}) /echo |- EVENT_CheckHaste ==>
  /if (!${checkEventArgs[${ChatSender},${line},UZ]}) /return
  /if (${Select[${Me.Class.ShortName},MNK,ROG,BRD,BER,WAR,SHD,PAL,BST]}>0 && ${Me.Haste}<225) /bc <<< [+Y+] Missing Haste! ${Me.Haste} out of 225! [+w+] <<<
  /if (${Select[${Me.Class.ShortName},MNK,ROG,BRD,BER,WAR,SHD,PAL,BST]}>0 && ${Me.Haste}<225 && ${Me.Haste}==200) /bc <<< [+Y+] Missing [+r+]Bard [+Y+]Overhaste! ${Me.Haste} / 225! [+w+] <<<
  /if (${Select[${Me.Class.ShortName},MNK,ROG,BRD,BER,WAR,SHD,PAL,BST]}>0 && ${Me.Haste}<225 && ${Me.Haste}==193) /bc <<< [+Y+] Missing [+o+]Worn [+Y+]Haste! ${Me.Haste} out of 225! [+w+] <<<
  /if (${Me.Haste}<225 && !${Bool[${Me.Buff[Hastening of Salik]}]} && ${Select[${Me.Class.ShortName},MNK,ROG,BRD,BER,WAR,SHD,PAL,BST]}>0 ) /bc <<< [+Y+] Missing [+R+]ENC Hastening of Salik! [+w+] <<<
 
/if (${Debug} || ${Debug_Basics}) /echo <== EVENT_CheckHaste -|
/RETURN

|--------------------------------------------------------|
|- MOD BY CHANCE
|- FOR PEQ USE
|- Searches inventory, and banks, for indicated items.	-|
|- Use, /bc Find ID 22191
|- DOES NOT SEARCH IN AUG SLOTS!
|- Don't Forget to add the line /doevents FindID 
|--------------------------------------------------------|
#EVENT FindID "<#1#> Find ID #2#"
SUB EVENT_FindID(line, ChatSender, ItemToFindID)
/if (!${checkEventArgs[${ChatSender},${line},U,${ItemToFindID}]}) /return
/varset ItemToFindID ${c_eventArgData}
  
  /declare reportDelay int local 1
  /declare reportArray[10] string local NIL
  /declare raINDX int local 1
  /declare i int local
  /declare e int local
  /declare r int local
  /declare LucidShard string local NIL
  /declare HasKey FALSE
  /declare ItemToFindID2 int local 9999999
  /declare ItemToFindID3 int local 9999999
  /if (${ItemToFindID}==22185) /varset LucidShard KEL
  /if (${ItemToFindID}==22186) /varset LucidShard DAT
  /if (${ItemToFindID}==22187) /varset LucidShard SET
  /if (${ItemToFindID}==22188) /varset LucidShard RAF
  /if (${ItemToFindID}==22189) /varset LucidShard VIN
  /if (${ItemToFindID}==22190) /varset LucidShard DAX
  /if (${ItemToFindID}==22191) /varset LucidShard LOR
  /if (${ItemToFindID}==22192) /varset LucidShard TAK
  /if (${ItemToFindID}==22193) /varset LucidShard VEX
  /if (${ItemToFindID}==22194) /varset LucidShard Kelara
  /if (${LucidShard.NotEqual[NIL]}) {
		/varset ItemToFindID2 22198
		/varset ItemToFindID3 17324
		}
| -Check cursor.
  /if (${Cursor.ID}==${ItemToFindID} ||${Cursor.ID}==22198||${Cursor.ID}==17324) {
    /varset reportArray[${raINDX}] [Cursor]${Cursor.Name}(${Cursor.ID}
	/if (${Cursor.ID}==${ItemToFindID2}) /varset HasKey TRUE
	/if (${Cursor.ID}==${ItemToFindID3}) /varset HasKey TRUE
    /varcalc raINDX ${raINDX}+1

  }
  /if (${Me.ID}>0) {
    | -Search Equippped Items.
    /for i 1 to 22
      /if (${InvSlot[${i}].Item.ID}==${ItemToFindID}||${InvSlot[${i}].Item.ID}==${ItemToFindID2}||${InvSlot[${i}].Item.ID}==${ItemToFindID3}) {
		/if (${InvSlot[${i}].Item.ID}==${ItemToFindID2}||${InvSlot[${i}].Item.ID}==${ItemToFindID3}) /varset HasKey TRUE
        /varset reportArray[${raINDX}] [Worn]${InvSlot[${i}].Item}(${InvSlot[${i}].Item.ID})
        /varcalc raINDX ${raINDX}+1
      }
    /next i
    | -Search packslots.
    /for i 1 to ${numInventorySlots}
    /if (${Me.Inventory[pack${i}].ID}==${ItemToFindID}||${Me.Inventory[pack${i}].ID}==${ItemToFindID2}||${Me.Inventory[pack${i}].ID}==${ItemToFindID3}) {
		/if (${Me.Inventory[pack${i}].ID}==${ItemToFindID2}||${Me.Inventory[pack${i}].ID}==${ItemToFindID3}) /varset HasKey TRUE
      /if (!${HasKey}) /varset reportArray[${raINDX}] [Pack]${Me.Inventory[pack${i}]}(${Me.Inventory[pack${i}].ID})
	  /if (!${HasKey}) /varset reportArray[${raINDX}] [Pack]${Me.Inventory[pack${i}]}(${Me.Inventory[pack${i}].ID})
      /varcalc raINDX ${raINDX}+1
    }
    /if (${Me.Inventory[pack${i}].Container}) {
      /for e 1 to ${Me.Inventory[pack${i}].Container}
        /if (${Me.Inventory[pack${i}].Item[${e}].ID}==${ItemToFindID}||${Me.Inventory[pack${i}].Item[${e}].ID}==${ItemToFindID2}||${Me.Inventory[pack${i}].Item[${e}].ID}==${ItemToFindID3}) {
			/if (${Me.Inventory[pack${i}].Item[${e}].ID}==${ItemToFindID2}||${Me.Inventory[pack${i}].Item[${e}].ID}==${ItemToFindID3}) /varset HasKey TRUE
          /if (!${HasKey}) /varset reportArray[${raINDX}] [Bag]${Me.Inventory[pack${i}].Item[${e}]}(${Me.Inventory[pack${i}].Item[${e}].ID})
          /if (!${HasKey}) /varcalc raINDX ${raINDX}+1
        }
      /next e
    }
    /next i
  }
| -Search bank packslots.
  /for i 1 to 26
  /if (${Me.Bank[${i}].ID}==${ItemToFindID}||${Me.Bank[${i}].ID}==${ItemToFindID2}||${Me.Bank[${i}].ID}==${ItemToFindID3}) {
	/if (${Me.Bank[${i}].ID}==${ItemToFindID2}||${Me.Bank[${i}].ID}==${ItemToFindID3}) /varset HasKey TRUE
    /if (!${HasKey}) /varset reportArray[${raINDX}] [Bank]${Me.Bank[${i}]}(${Me.Bank[${i}].ID})
    /if (!${HasKey}) /varcalc raINDX ${raINDX}+1
  }
  /if (${Me.Bank[${i}].Container}) {
    /for e 1 to ${Me.Bank[${i}].Container}
    /if (${Me.Bank[${i}].Item[${e}].ID}==${ItemToFindID}||${Me.Bank[${i}].Item[${e}].ID}==${ItemToFindID2}||${Me.Bank[${i}].Item[${e}].ID}==${ItemToFindID3}) {
		/if (${Me.Bank[${i}].Item[${e}].ID}==${ItemToFindID2}||${Me.Bank[${i}].Item[${e}].ID}==${ItemToFindID3}) /varset HasKey TRUE
      /if (!${HasKey}) /varset reportArray[${raINDX}] [Bank]${Me.Bank[${i}].Item[${e}]}(${Me.Bank[${i}].Item[${e}].ID})
      /if (!${HasKey}) /varcalc raINDX ${raINDX}+1
    }
    /next e
  }
  /next i
/if (${HasKey}) /varset LucidShard KEY
  /for r 1 to ${raINDX}
    /if (${reportArray[${r}].NotEqual[NIL]} && ${LucidShard.NotEqual[NIL]}) /docommand ${ChatToggle} [+g+] ${reportArray[${r}]} - ${LucidShard}
	/if (${reportArray[${r}].NotEqual[NIL]} && ${LucidShard.Equal[NIL]}) /docommand ${ChatToggle} ${reportArray[${r}]} 
  /next r
/if (${raINDX}==1 && ${LucidShard.Equal[KEY]}) /echo \ag  NOT NEEDED I HAVE THE KEY - ${LucidShard}
/if (${raINDX}==1 && ${LucidShard.NotEqual[NIL]} && ${LucidShard.NotEqual[KEY]}) /bc [+R+] NO- Lucid Shard - ${LucidShard}

  /if (${Debug} || ${Debug_Basics}) /echo <== EVENT_FindItems -|
/RETURN