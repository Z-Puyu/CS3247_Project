# CS3247 Project Development Plan

## Segregation of Duties

- Map & Exploration: Chengzhen & Gerard

- Combat: Yiwen & Yuxiang

- Card Crafting: Puyu & Yirui

- UI: Unassigned during the prototyping phase.

## Workflow

### Main Protection Rules

- The **main branch** is protected and no direct commit should be made to it.

- Create a separate **branch** to implement and test new features.

- Open a **pull request** to merge a branch to the main branch.

### Branch Naming Conventions

- A branch should be named by the **author's name**.

- If you want to indicate the feature being worked on in the branch, include a short description in a bracket.

- Preferably, spell the branch name with all lower-case letters.

- Example: `puyu (card crafting recipes)`.

### Project Management

- **Team meeting at 14:00 every Monday** to update previous week's progress and next week's plan.

- We use [Jira](https://zpyzhangpuyu.atlassian.net/jira/software/projects/CS3247/boards/1) for team management.

- Create a Jira issue for **every piece of work** and let Jira track your commits.

- Jira issue types:

  - **Feature**: Ideas/suggestions for new features.

  - **Bug**: Bug fixes.

  - **Task**: New features currently being worked on. Every task requires a **deadline**.

- Jira issue labels:

  - **In-Progress**: Actively worked on.

  - **Need-Help**: Stuck and need help.

  - **Abandoned**: Development is stopped and another person hopefully can take this over.

  - **Pending-Test**: Completed but waiting to be tested.

- Useful links:

  - [Reference Jira Issues when Committing](https://support.atlassian.com/jira-software-cloud/docs/reference-issues-in-your-development-work/)

  - [UE5 Coding Standards](https://dev.epicgames.com/documentation/en-us/unreal-engine/epic-cplusplus-coding-standard-for-unreal-engine)

  - [UE5 C++ Scripting](https://dev.epicgames.com/documentation/en-us/unreal-engine/programming-with-cplusplus-in-unreal-engine)

## Things to Implement

In each category, the items are ranked in descending importance.

- Map & Exploration (2 persons before 2 Mar, 1 person after)
  
  - 1st person movement

  - Enemy encounters

  - Procedural dungeon generation

  - Player inventory

  - Interactable objects (e.g. treasure chests, collectibles)

- Combat (2 persons)
  
  - Turn-based combat loop

  - Playing cards

  - Enemy AI

  - Loot & reward system

  - Enemy intent

- Card Crafting (2 persons before 2 Mar, 1 person after)
  
  - Data containers for cards and card effects

  - Data containers for recipes and resources

  - Single-card crafting

  - Card effect crafting

  - Destroying cards

- UI (2 persons starting from 2 Mar)
  
  - Save & Load system and UI

  - Card UI

  - Player & enemy status UI

  - Craft station UI

  - Recipe, resources and card effect icons

  - Pause menus etc.

## Rough Timeline

### Important Dates

- **7 Mar**: prototyping phase presentation - need a MVP by then.
  
- **28 Mar**: alpha phase presentation - need a playable level by then.
  
- **31 Mar**: beta phase executable - need to complete first round of play-testing and fix major bugs by then.
  
- **18 Apr**: final presentation - have 2.5 weeks to polish everything.
  
### Plan

Note: up until 2 Mar, there's not much to do for UI so whoever has the free time just do it. After the prototyping presentation, we start implementing the UI properly by allocating 2 persons.

- By 23 Feb:
  
  - Map & Exploration: implement player **movement** and have a small test scene

  - Combat: implement a **dummy enemy** and **dummy cards**. Implement the **turn-based combat loop** to test

  - Card crafting: implement data containers for cards and card effects

  - UI: have a simple main menu

- By 2 Mar:
  
  - Map & Exploration: implement **enemy encounters** (re-use the dummy enemy from previous week to test)

  - Combat: implement **simple enemy actions and basic AI** (e.g. purely random selection).

  - Card crafting: implement **single-card crafting**

  - UI: have a simple menu to view the player's deck

- By 7 Mar (**Prototype**): test and debug to make sure everything works.
  
- By 16 Mar (more time due to mid-term week):
  
  - Map & Exploration: implement **procedural map generation** and random placement of enemy encounter events.

  - Combat: **polish enemy AI** into a full-fledged version.

  - Card crafting: implement **card-effect crafting**. Add some basic recipes.

  - UI: Implement **Card UI and player/enemy status** (e.g. health bars etc.). Make sure they are responsive to combat events. Implement save & load.

- By 23 Mar:
  
  - Map & Exploration: implement a **player inventory** system for cards and resources.

  - Combat: implement **loot & reward** system after a combat ends. Make sure the system interacts with the inventory system well.

  - Card crafting: implement **destroying cards**

  - UI: implement **icons for recipes, resources and card effects**. Implement **craft station UI for card crafting**. Implement save & load.

- By 29 Mar (**Alpha**):
  
  - Map & Exploration: implement **treasure chests** and **merchant**.

  - Combat: implement **enemy intents**. **Design a few enemy types** and a **boss enemy** for Alpha presentation.

  - Card crafting: add more recipes and card effects for Alpha presentation.

  - UI: implement **the rest of the craft station UI**. Implement save & load.

- By 31 Mar (**Beta**): play-test and fix bugs.
  
- By 11 Apr:
  
  - Map & Exploration: implement **more interactable objects** and **collectibles** (e.g. adventurer journals to enhance game lore, corpses which can be searched for loot etc.)

  - Combat: **design more enemy types** and in particular **bosses**.

  - Card crafting: polish anything which needs polishing and help with other parts.

  - UI: enhance aesthetics, add a game setting menu.

- By 18 Apr (**Final**): play-test and fix bugs.
