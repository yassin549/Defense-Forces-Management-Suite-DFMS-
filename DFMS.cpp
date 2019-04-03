#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <fstream>
#include <string>
using namespace std;

int screen_size();
int rows_of_screen, columns_of_screen;
int rows_to_fit, columns_to_fit;
// LOGIN PHASE
int user_id();
string take_password();
string take_username();
bool ams_user_password_login(string user, string password);
bool nms_user_password_login(string user, string password);
bool afms_user_password_login(string user, string password);
bool air_force_officer_user_password_login(string user, string password);
bool navy_officer_user_password_login(string user, string password);
bool army_officer_user_password_login(string user, string password);
bool army_soldier_user_password_login(string user, string password);

// Validations
bool numeric_validation(string word);
bool soldiers_batch_id_validations(string word);
bool validation_in_adding_soldiers_persons(int arr_index,string word);
bool password_validation(string word);
bool character_type_validation(string word);
bool validation_in_adding_officers_persons(int arr_index,string word);
bool officer_batch_id_validations(string word);
// DESIGN PHASE DECISION PHASE
void title(string content_inside_title);
void to_print_in_title(string content_inside_title);
void print_start_box(int rows, int columns);
char getCharAtxy(short int x, short int y);
void gotoxy(int x, int y);
void home_page();
void print_line(int start_point, int row, int end_point);
void first_page_title();
int selecting_function(int x, int y, int n);
void slecter_horizantel_line(int x, int y);
void erase_slecter_horizantel_line(int x, int y);
void invalid_function();
void to_show_note(string text);

// USERS
int army_management_team_system(int checker_of_user_domain);
int navy_management_team_system(int checker_of_user_domain);
int air_force_management_team_system(int checker_of_user_domain);
int army_officer_management_system(int checker_of_user_domain);
int air_force_officer_management_system(int checker_of_user_domain);
int navy_officer_management_system(int checker_of_user_domain);
int soldiers_management_system(int checker_of_user_domain);
// SECURITY PHASE
string batch_id_security;
int batch_id_index_security;
// VARIABLES FOR COUNT THINGS
int army_soldier_count = 0;
int navy_soldier_count = 0;
int air_force_soldier_count = 0;
int army_officer_count = 0;
int navy_officer_count = 0;
int air_force_officer_count = 0;
// Variable for retired 
int retired_army_soldier_count = 0;
int retired_navy_soldier_count = 0;
int retired_air_force_soldier_count = 0;
int retired_army_officer_count = 0;
int retired_navy_officer_count = 0;
int retired_air_force_officer_count = 0;
// ARRAYS
string army_soldier_array[8][1000];
string navy_soldier_array[8][1000];
string air_force_soldier_array[8][1000];
string army_officer_array[8][1000];
string navy_officer_array[8][1000];
string air_force_officer_array[8][1000];
// ARRAYS FOR RETIRED SOLDIERS
string retired_army_soldier_array[8][1000];
string retired_navy_soldier_array[8][1000];
string retired_air_force_soldier_array[8][1000];
string retired_army_officer_array[8][1000];
string retired_navy_officer_array[8][1000];
string retired_air_force_officer_array[8][1000];
// SOLDIERS UNDER THE OFFICER
string soldiers_under_the_officer_ams[2][1000];
string soldiers_under_the_officer_nms[2][1000];
string soldiers_under_the_officer_afms[2][1000];
// INSTRUMENTS AMS
int count_ams_weapons = 0;
int count_ams_carriers = 0;
int count_ams_missilies = 0;
int count_ams_tank = 0;
int count_ams_atomic_bombs = 0;
string ams_weapons[30][5];
string ams_carriers[30][5];
string ams_missilies[30][5];
string ams_tank[30][5];
string ams_atomic_bombs[30][5];
int count_nms_weapons = 0;
int count_nms_air_craft = 0;
int count_nms_missilies = 0;
int count_nms_subarine = 0;
int count_nms_surface_ships = 0;
string nms_weapons[30][5];
string nms_air_craft[30][5];
string nms_missilies[30][5];
string nms_subarine[30][5];
string nms_surface_ships[30][5];
int count_afms_weapons = 0;
int count_afms_air_craft = 0;
int count_afms_missilies = 0;
int count_afms_planes = 0;
int count_afms_trackers = 0;
string afms_weapons[30][5];
string afms_air_craft[30][5];
string afms_missilies[30][5];
string afms_planes[30][5];
string afms_trackers[30][5];
// fetch Instruments
int fetch_ams_carriers();
int fetch_ams_weapons();
int fetch_ams_tank();
int fetch_ams_missilies();
int fetch_ams_bombs();
int fetch_nms_weapons();
int fetch_nms_air_craft();
int fetch_nms_missilies();
int fetch_nms_subarine();
int fetch_nms_surface_ships();
int fetch_afms_air_craft();
int fetch_afms_weapons();
int fetch_afms_missilies();
int fetch_afms_planes();
int fetch_afms_trackers();
// SELECTION FUNCTIONS
int yes_or_no(int perior_option);
void feedback();
int to_calculate_salary_asms();
// fetching functions
void fetch_all_data_at_start();
int fetch_ams_soldier_data_from_txt_to_array();
int fetch_ams_officers_data_from_txt_to_array();
int fetch_nms_soldier_data_from_txt_to_array();
int fetch_nms_officers_data_from_txt_to_array();
int fetch_afms_soldier_data_from_txt_to_array();
int fetch_afms_officers_data_from_txt_to_array();
int fetch_ams_retired_soldiers_data_from_txt_to_array();
int fetch_ams_retired_officers_data_from_txt_to_array();
int fetch_nms_retired_soldiers_data_from_txt_to_array();
int fetch_nms_retired_officers_data_from_txt_to_array();
int fetch_afms_retired_soldiers_data_from_txt_to_array();
int fetch_afms_retired_officers_data_from_txt_to_array();

// AMS TEAM USER 1 THINGS
string main_menu_names_ams[5] = {"1. ARMY SOLDIERS", "2. ARMY OFFICERS", "3. INSTRUMENTS", "4. CROPS", "5. REPORT OF ARMY WORK"};
string sub_menu_army_soldiers_ams[5] = {"1. PERSONAL DETAILS", "2. ADD NEW SOLDIER", "3. EDIT SOLDIER DETAIL", "4. RETIRED GENERIALS", "5. MARTYRED"};
string sub_menu_instruments_ams[5] = {"1. DETAILS OF INSTRUMENT", "2. ADD NEW INSTRUMENTS", "3. EDIT INSTRUMENT DETAIL", "4. GRAPH OF INSTRUMENTS(RESULT OF BUDGET)", "5. BUDGET OF INSTRUMENT"};
string personal_details_options_ams_soldiers[8] = {"SOLDIER BATCH ID      : ", "SOLDIER NAME    : ", "SOLDIER FATHER NAME  : ", "SOLDIER PROVIENCE : ", "SOLDIER SALARY : ", "SOLDIER AGE : ", "SOLDIER RANK : ", "SOLDIER ID PASSWORD"};
string retired_options_ams[2] = {"1. VIEW RETIRED ", "2. ADD NEW RETIRED MEN"};
string personal_details_options_ams_officers[8] = {"OFFICER BATCH ID      : ", "OFFICER NAME    : ", "OFFICER FATHER NAME  : ", "OFFICER PROVIENCE : ", "OFFICER SALARY : ", "OFFICER AGE : ", "OFFICER RANK : ", "OFFICER ID PASSWORD"};
string sub_menu_army_officers_ams[7] = {"1. PERSONAL DETAILS", "2. ADD NEW OFFICERS", "3. EDIT OFFICER DETAILS", "4. RETIRED OFFICER", "5. MARTYRED", "6. OFFICERS IN PROVIENCE", "7. SOLDIERS UNDER OFFICERS"};
string sub_of_sub_menu_instruments_ams[5] = {"1. CARRIERS", "2. WEAPONS", "3. MISSILES", "4. TANKS", "5. ATOMIC BOMBS"};
string readable_instruments_ams[5] = {"NAME: ", "RANGE: ", "PRICE: ", "STOCK: ", "USING: "};
string ams_crops[2] = {"1. XXX-KHOR", "2. SOC-KHOR"};
string matryed_option[2] = {"1. VIEW HEROES OF NATION", "2. ADD NEW MATRYED"};
int to_show_main_menu_ams(int no_of_index);
int to_show_sub_menu_army_soldier_ams(int no_of_index);
int id_take_to_fetch_and_id_check_soldiers_ams();
int to_show_personal_details_from_soldiers_array(int batch_id_index);
void to_show_personal_details_options_soldiers_ams();
void to_add_data_in_soldiers_array_ams();
void to_add_data_in_soldier_txt_ams();
void to_edit_data_in_soldiers_array_ams(int batch_id_index);
void to_add_whole_data_in_soldier_txt_ams();
int to_show_retired_menu_ams(int no_of_index);
void to_view_retired_soldier_data_ams();
void to_add_removed_soldier_in_retired_ams(int batch_index);
void to_remove_retired_soldier_from_array_ams(int batch_index);
void to_add_whole_data_in_retired_soldier_txt_ams();
int to_show_matryed_menu_ams(int no_of_index);
int to_view_matryed(string address);
int to_add_matryed(string address);
    // sub menu 2
int to_show_sub_menu_army_officer_ams(int no_of_index);
int id_take_to_fetch_and_id_check_officer_ams();
int to_show_personal_details_from_officer_array(int batch_id_index);
void to_show_personal_details_options_officer_ams();
void to_show_personal_details_options_officer_ams();
void to_add_data_in_officer_array_ams();
void to_add_data_in_officer_txt_ams();
void to_edit_data_in_officer_array_ams(int batch_id_index);
void to_add_whole_data_in_officer_txt_ams();
void to_view_retired_officer_data_ams();
void to_add_removed_officer_in_retired_ams(int batch_index);
void to_remove_retired_officer_from_array_ams(int batch_index);
void to_add_whole_data_in_retired_officer_txt_ams();
int to_see_data_from_ams_officer_arrray(int row,string provience);
string to_take_provience();
void soldier_under_officers_ams();
void soldier_under_officer_view_ams(int batch_id);
void soldier_under_officers_ams();
// sub op 3
int to_show_sub_menu_army_instruments_ams(int no_of_index);
int to_show_sub_detail_view_army_instruments_ams(int no_of_index);
void to_show_carriers_details();
void to_show_weapons_details();
void to_show_missilies_details();
void to_show_tank_details();
void to_show_atomic_bombs_details();
void to_add_data_in_array_carrier();
void to_add_data_in_array_weapons();
void to_add_data_in_array_missilies();
void to_add_data_in_array_tank();
void to_add_data_in_array_bomb();
bool validation_check_instruments(int n, string word);
void to_add_data_of_carrier_in_txt();
void to_add_data_of_weapons_in_txt();
void to_add_data_of_bomb_in_txt();
void to_add_data_of_missilies_in_txt();
void to_add_data_of_tank_in_txt();
void to_edit_instrument_record_carriers();
void to_edit_instrument_record_weapons();
void to_edit_instrument_record_tank();
void to_edit_instrument_record_missilies();
void to_edit_instrument_record_bombs();
void to_add_whole_data_in_txt_carriers();
void to_add_whole_data_in_txt_tank();
void to_add_whole_data_in_txt_weapons();
void to_add_whole_data_in_txt_missilies();
void to_add_whole_data_in_txt_bombs();
void graph_ams();
void total_ams_budget();
// SUB OP 4
int to_show_sub_menu_army_crops_ams(int no_of_index);
void to_show_soc_khor();
void to_show_xxx_khor();
// sub op 5
void to_fetch_feedback();
//                               NMS USER
string main_menu_names_nms[5] = {"1. NAVY SOLDIERS", "2. NAVY OFFICERS", "3. INSTRUMENTS", "4. CROPS", "5. REPORT OF NAVY WORK"};
string sub_menu_navy_soldiers_nms[5] = {"1. PERSONAL DETAILS", "2. ADD NEW SOLDIER", "3. EDIT SOLDIER DETAIL", "4. RETIRED SOLDIERS", "5. MARTYRED"};
string sub_menu_instruments_nms[5] = {"1. DETAILS OF INSTRUMENT", "2. ADD NEW INSTRUMENTS", "3. EDIT INSTRUMENT DETAIL", "4. GRAPH OF INSTRUMENTS(RESULT OF BUDGET)", "5. BUDGET OF INSTRUMENT"};
string personal_details_options_nms_soldiers[8] = {"SOLDIER BATCH ID      : ", "SOLDIER NAME    : ", "SOLDIER FATHER NAME  : ", "SOLDIER PROVIENCE : ", "SOLDIER SALARY : ", "SOLDIER AGE : ", "SOLDIER RANK : ", "SOLDIER ID PASSWORD"};
string retired_options_nms[2] = {"1. VIEW RETIRED ", "2. ADD NEW RETIRED PERSON"};
string personal_details_options_nms_officers[8] = {"OFFICER BATCH ID      : ", "OFFICER NAME    : ", "OFFICER FATHER NAME  : ", "OFFICER PROVIENCE : ", "OFFICER SALARY : ", "OFFICER AGE : ", "OFFICER RANK : ", "OFFICER ID PASSWORD"};
string sub_menu_navy_officers_nms[7] = {"1. PERSONAL DETAILS", "2. ADD NEW OFFICERS", "3. EDIT OFFICER DETAILS", "4. RETIRED OFFICER", "5. MARTYRED", "6. OFFICERS IN PROVIENCE", "7. SOLDIERS UNDER OFFICERS"};
string sub_of_sub_menu_instruments_nms[5] = {"1. AIR CRAFT", "2. WEAPONS", "3. MISSILES", "4. SUBARINE", "5. SURFACE SHIP"};
string readable_instruments_nms[5] = {"NAME: ", "RANGE: ", "PRICE: ", "STOCK: ", "USING: "};
string nms_crops[2] = {"1. NAVAL-KHOR", "2. NAIZI-KHOR"};
int to_show_main_menu_nms(int no_of_index);
int to_show_sub_menu_navy_soldier_nms(int no_of_index);
int id_take_to_fetch_and_id_check_soldiers_nms();
int to_show_personal_details_from_navy_soldiers_array(int batch_id_index);
void to_show_personal_details_options_soldiers_nms();
void to_add_data_in_soldiers_array_nms();
void to_add_data_in_soldier_txt_nms();
void to_edit_data_in_soldiers_array_nms(int batch_id_index);
void to_add_whole_data_in_soldier_txt_nms();
int to_show_retired_menu_nms(int no_of_index);
void to_view_retired_soldier_data_nms();
void to_add_removed_soldier_in_retired_nms(int batch_index);
void to_remove_retired_soldier_from_array_nms(int batch_index);
void to_add_whole_data_in_retired_soldier_txt_nms();
int to_show_matryed_menu_nms(int no_of_index);
int to_view_matryed(string address);
int to_add_matryed(string address);
    // sub menu 2
int to_show_sub_menu_navy_officer_nms(int no_of_index);
int id_take_to_fetch_and_id_check_officer_nms();
int to_show_personal_details_from_navy_officer_array(int batch_id_index);
void to_show_personal_details_options_officer_nms();
void to_show_personal_details_options_officer_nms();
void to_add_data_in_officer_array_nms();
void to_add_data_in_officer_txt_nms();
void to_edit_data_in_officer_array_nms(int batch_id_index);
void to_add_whole_data_in_officer_txt_nms();
void to_view_retired_officer_data_nms();
void to_add_removed_officer_in_retired_nms(int batch_index);
void to_remove_retired_officer_from_array_nms(int batch_index);
void to_add_whole_data_in_retired_officer_txt_nms();
int to_see_data_from_nms_officer_arrray(int row,string provience);
string to_take_provience();
void soldier_under_officers_nms();
void soldier_under_officer_view_nms(int batch_id);
void soldier_under_officers_nms();
// sub op 3
int to_show_sub_menu_navy_instruments_nms(int no_of_index);
int to_show_sub_detail_view_navy_instruments_nms(int no_of_index);
void to_show_air_craft_details();
void to_show_weapons_details_navy();
void to_show_missilies_details_navy();
void to_show_subarine_details();
void to_show_surface_ships_details();
void to_add_data_in_array_air_craft();
void to_add_data_in_array_weapons_navy();
void to_add_data_in_array_missilies_navy();
void to_add_data_in_array_subarine();
void to_add_data_in_array_surface_ship();
void to_add_data_of_air_craft_in_txt();
void to_add_data_of_weapons_in_txt_navy();
void to_add_data_of_surface_ship_in_txt();
void to_add_data_of_missilies_in_txt_navy();
void to_add_data_of_subarine_in_txt();
void to_edit_instrument_record_air_craft();
void to_edit_instrument_record_weapons_navy();
void to_edit_instrument_record_subarine();
void to_edit_instrument_record_missilies_navy();
void to_edit_instrument_record_surface_ships();
void to_add_whole_data_in_txt_air_craft();
void to_add_whole_data_in_txt_subarine();
void to_add_whole_data_in_txt_weapons_navy();
void to_add_whole_data_in_txt_missilies_navy();
void to_add_whole_data_in_txt_surface_ships();
void graph_nms();
void total_nms_budget();
// SUB OP 4
int to_show_sub_menu_navy_crops_nms(int no_of_index);
void to_show_naizi_khor();
void to_show_naval_khor();
//                          AFMS
//                               AFMS USER
string main_menu_names_afms[5] = {"1. AIR FORCE SOLDIERS", "2. AIR FORCE OFFICERS", "3. INSTRUMENTS", "4. CROPS", "5. REPORT OF AIR FORCE WORK"};
string sub_menu_air_force_soldiers_afms[5] = {"1. PERSONAL DETAILS", "2. ADD NEW SOLDIER", "3. EDIT SOLDIER DETAIL", "4. RETIRED SOLDIERS", "5. MARTYRED"};
string sub_menu_instruments_afms[5] = {"1. DETAILS OF INSTRUMENT", "2. ADD NEW INSTRUMENTS", "3. EDIT INSTRUMENT DETAIL", "4. GRAPH OF INSTRUMENTS(RESULT OF BUDGET)", "5. BUDGET OF INSTRUMENT"};
string personal_details_options_afms_soldiers[8] = {"SOLDIER BATCH ID      : ", "SOLDIER NAME    : ", "SOLDIER FATHER NAME  : ", "SOLDIER PROVIENCE : ", "SOLDIER SALARY : ", "SOLDIER AGE : ", "SOLDIER RANK : ", "SOLDIER ID PASSWORD"};
string retired_options_afms[2] = {"1. VIEW RETIRED ", "2. ADD NEW RETIRED PERSON"};
string personal_details_options_afms_officers[8] = {"OFFICER BATCH ID      : ", "OFFICER NAME    : ", "OFFICER FATHER NAME  : ", "OFFICER PROVIENCE : ", "OFFICER SALARY : ", "OFFICER AGE : ", "OFFICER RANK : ", "OFFICER ID PASSWORD"};
string sub_menu_air_force_officers_afms[7] = {"1. PERSONAL DETAILS", "2. ADD NEW OFFICERS", "3. EDIT OFFICER DETAILS", "4. RETIRED OFFICER", "5. MARTYRED", "6. OFFICERS IN PROVIENCE", "7. SOLDIERS UNDER OFFICERS"};
string sub_of_sub_menu_instruments_afms[5] = {"1. AIR CRAFT", "2. WEAPONS", "3. MISSILES", "4. planes", "5. SURFACE SHIP"};
string readable_instruments_afms[5] = {"NAME: ", "RANGE: ", "PRICE: ", "STOCK: ", "USING: "};
string afms_crops[2] = {"1. NAVAL-KHOR", "2. NAIZI-KHOR"};
string soldiers_main_menu_asms[3] = {"1. VIEW PERSONAL DETAILS", "2. CALCULATE SALARY", "3. FEEDBACK"};
string personal_details_options_asms[8] = {"SOLDIER BATCH ID      : ", "SOLDIER NAME    : ", "SOLDIER FATHER NAME  : ", "SOLDIER PROVIENCE : ", "SOLDIER SALARY : ", "SOLDIER AGE : ", "SOLDIER RANK : ", "SOLDIER ID PASSWORD"};
int to_show_main_menu_afms(int no_of_index);
int to_show_sub_menu_air_force_soldier_afms(int no_of_index);
int id_take_to_fetch_and_id_check_soldiers_afms();
int to_show_personal_details_from_air_force_soldiers_array(int batch_id_index);
void to_show_personal_details_options_soldiers_afms();
void to_add_data_in_soldiers_array_afms();
void to_add_data_in_soldier_txt_afms();
void to_edit_data_in_soldiers_array_afms(int batch_id_index);
void to_add_whole_data_in_soldier_txt_afms();
int to_show_retired_menu_afms(int no_of_index);
void to_view_retired_soldier_data_afms();
void to_add_removed_soldier_in_retired_afms(int batch_index);
void to_remove_retired_soldier_from_array_afms(int batch_index);
void to_add_whole_data_in_retired_soldier_txt_afms();
int to_show_matryed_menu_afms(int no_of_index);
int to_view_matryed(string address);
int to_add_matryed(string address);
    // sub menu 2
int to_show_sub_menu_air_force_officer_afms(int no_of_index);
int id_take_to_fetch_and_id_check_officer_afms();
int to_show_personal_details_from_air_force_officer_array(int batch_id_index);
void to_show_personal_details_options_officer_afms();
void to_show_personal_details_options_officer_afms();
void to_add_data_in_officer_array_afms();
void to_add_data_in_officer_txt_afms();
void to_edit_data_in_officer_array_afms(int batch_id_index);
void to_add_whole_data_in_officer_txt_afms();
void to_view_retired_officer_data_afms();
void to_add_removed_officer_in_retired_afms(int batch_index);
void to_remove_retired_officer_from_array_afms(int batch_index);
void to_add_whole_data_in_retired_officer_txt_afms();
int to_see_data_from_afms_officer_arrray(int row,string provience);
string to_take_provience();
void soldier_under_officers_afms();
void soldier_under_officer_view_afms(int batch_id);
void soldier_under_officers_afms();
// sub op 3
int to_show_sub_menu_air_force_instruments_afms(int no_of_index);
int to_show_sub_detail_view_air_force_instruments_afms(int no_of_index);
void to_show_air_craft_details_air_force();
void to_show_weapons_details_air_force();
void to_show_missilies_details_air_force();
void to_show_planes_details();
void to_show_trackers_details();
void to_add_data_in_array_air_craft_air_force();
void to_add_data_in_array_weapons_air_force();
void to_add_data_in_array_missilies_air_force();
void to_add_data_in_array_planes();
void to_add_data_in_array_trackers();
void to_add_data_of_air_craft_in_txt_air_force();
void to_add_data_of_weapons_in_txt_air_force();
void to_add_data_of_trackers_in_txt();
void to_add_data_of_missilies_in_txt_air_force();
void to_add_data_of_planes_in_txt();
void to_edit_instrument_record_air_craft_air_force();
void to_edit_instrument_record_weapons_air_force();
void to_edit_instrument_record_planes();
void to_edit_instrument_record_missilies_air_force();
void to_edit_instrument_record_trackers();
void to_add_whole_data_in_txt_air_craft_air_force();
void to_add_whole_data_in_txt_planes();
void to_add_whole_data_in_txt_weapons_air_force();
void to_add_whole_data_in_txt_missilies_air_force();
void to_add_whole_data_in_txt_trackers();
void graph_afms();
void total_afms_budget();
// SUB OP 4
int to_show_sub_menu_air_force_crops_afms(int no_of_index);
void to_show_him_khor();
void to_show_nav_khor();
//                                  user 4
string gto_tasks_marks[5][6];
string psychologist_tasks_marks[5][6];
string candidate_batch_id[5];
int total_candidatr_marks_gto[5];
int total_candidatr_marks_psychologist[5];
string aoms_main_menus[5] = {"1. PERSONAL DETAILS", "2. VIEW SOLDIERS", "3. CANDIDATES SELECTOR", "4. WAR IDEA", "5. CODE BY CROPS"};
string aoms_issb_selector_option[2] = {"1. GTO", "2. PSYCHOLOGYIST"};
string gto_tasks[6] = {"MILTARY PLANING", "GROUP DISCUSSION", "OUTDOOR TASK", "OBSTACLES", "LECTURE", "TEAM WORK"};
string psychologist_tasks[6] = {"WORDS TESTS", "ALGORITHM TEST", "INTERVIEW", "ATITUDE", "SCREEN TEST", "NON VERBAL TEST"};
int to_show_main_menu_aoms(int no_of_index);
int to_show_personal_details_from_aoms();
void to_show_personal_details_options_aoms();
int to_show_gto_tasks(int no_of_index);
int to_show_psychologist_tasks(int no_of_index);
int to_get_candidate_marks_gto();
int to_get_candidate_marks_psychologist();
int to_show_personal_selector_details_options_aoms(int no_of_index);
int to_input_war_ideas();
int to_show_main_war_ideas();
int code_by_corp();
void to_add_data_in_txt_feedback_psychologist();
void to_add_data_in_txt_feedback_gto();
void to_get_candidates_batch_id();
// 5 and 6th user
int to_show_personal_details_from_noms();
int to_show_personal_details_from_afoms();
//                              ASMS THINGS USER 7
int to_show_main_menu_asms(int no_of_index);
void to_show_personal_details_options_asms();
int to_show_personal_details_from_asms();
main()
{
    fetch_all_data_at_start();
    int checker_of_user_domain;
user_login:
    screen_size();
    checker_of_user_domain = user_id();

    if (checker_of_user_domain == 1)
    {
        army_management_team_system(checker_of_user_domain);
        goto user_login;
    }
    if (checker_of_user_domain == 2)
    {
        navy_management_team_system(checker_of_user_domain);
        goto user_login;
    }
    if (checker_of_user_domain == 3)
    {
        air_force_management_team_system(checker_of_user_domain);
        goto user_login;
    }
    if (checker_of_user_domain == 4)
    {
        army_officer_management_system(checker_of_user_domain);
        goto user_login;
    }
    
    if (checker_of_user_domain == 5)
    {
        navy_officer_management_system(checker_of_user_domain);
        goto user_login;
    }
    
    if (checker_of_user_domain == 6)
    {
        air_force_officer_management_system(checker_of_user_domain);
        goto user_login;
    }
    if (checker_of_user_domain == 7)
    {
        soldiers_management_system(checker_of_user_domain);
        goto user_login;
    }
}
// 1. ARMY MANAGEMENT SYSTEM
int army_management_team_system(int checker_of_user_domain)
{
    
    int sub_selected_instruments;
    int main_selected_option_of_ams;
    int sub_select_of_army_instruments_ams, sub_select_of_army_soldier_ams, sub_select_of_army_officer_ams;
    int item_quantity[5];
// Main Menu of ARMY TEAM MANAGEMENT SYSTEM
    ams_top_menu:
    title("ARMY TEAM MANAGEMENT SYSTEM");
    to_show_main_menu_ams(5);
    main_selected_option_of_ams = selecting_function(columns_of_screen / 3 + 10,12,5);
    // army soldiers in ams // COMPLETE
    while (main_selected_option_of_ams == 1)
    {
        army_soldiers_menu:
        title("ARMY TEAM MANAGEMENT SYSTEM");
        to_show_sub_menu_army_soldier_ams(5);
        sub_select_of_army_soldier_ams = selecting_function(columns_of_screen / 3 + 10,12,5);
        // View Personal details of Soldiers 1
        while (sub_select_of_army_soldier_ams == 1)
        {
            int check_batch_id;
            int batch_id_idx;
            title("PERSONAL DETAILS OF ARMY SOLDIER");
            batch_id_idx = id_take_to_fetch_and_id_check_soldiers_ams();
            check_batch_id = to_show_personal_details_from_soldiers_array(batch_id_idx);
            if (check_batch_id == 1)
            {
                sub_select_of_army_soldier_ams = yes_or_no(sub_select_of_army_soldier_ams);
                if (sub_select_of_army_soldier_ams == 0 )
                {
                    goto army_soldiers_menu;
                }
            }
        }
        // ADD NEW RECORD 2
        while (sub_select_of_army_soldier_ams == 2)
        {
            title("ADD DETAILS OF ARMY SOLDIER");
            to_show_note("120-");
            to_add_data_in_soldiers_array_ams();
            to_add_data_in_soldier_txt_ams();
            sub_select_of_army_soldier_ams = yes_or_no(sub_select_of_army_soldier_ams);
            if (sub_select_of_army_soldier_ams == 0 )
            {   

                goto army_soldiers_menu;
            }
        }
        // EDIT RECORD 3
        while (sub_select_of_army_soldier_ams == 3)
        {
            int check_batch_idx;
            int batch_id_index;
            title("EDIT DETAILS OF ARMY SOLDIER");
            batch_id_index = id_take_to_fetch_and_id_check_soldiers_ams();
            to_edit_data_in_soldiers_array_ams(batch_id_index);
            to_add_whole_data_in_soldier_txt_ams();
            sub_select_of_army_soldier_ams = yes_or_no(sub_select_of_army_soldier_ams);
            if (sub_select_of_army_soldier_ams == 0)
            {
                goto army_soldiers_menu;
            }
        }
        // RETIRED OFFICERS 4
        while (sub_select_of_army_soldier_ams == 4)
        {   retired_main_menu:
            int sub_option_of_retired_soldiers;
            title("RETIRED SOLDIERS MANAGEMENT");
            to_show_retired_menu_ams(2);
            sub_option_of_retired_soldiers = selecting_function(columns_of_screen / 3 + 10, 17,2);
            // to view retired soldiers
            while(sub_option_of_retired_soldiers == 1)
            {
                to_view_retired_soldier_data_ams();
                sub_option_of_retired_soldiers = yes_or_no(sub_option_of_retired_soldiers);
                if(sub_option_of_retired_soldiers == 0)
                {
                    goto retired_main_menu;
                }
            }
            // to add new retired soldiers
            while(sub_option_of_retired_soldiers == 2)
            {
                int batch_id_index;
                batch_id_index = id_take_to_fetch_and_id_check_soldiers_ams();
                to_add_removed_soldier_in_retired_ams(batch_id_index);
                to_remove_retired_soldier_from_array_ams(batch_id_index);
                to_add_whole_data_in_soldier_txt_ams();
                to_add_whole_data_in_retired_soldier_txt_ams();
                sub_option_of_retired_soldiers = yes_or_no(sub_option_of_retired_soldiers);
                if(sub_option_of_retired_soldiers == 0)
                {
                    goto retired_main_menu;
                }
            }

            if(sub_option_of_retired_soldiers == 3)
            {
                goto army_soldiers_menu;
            }
            
        }
        // MATRYED 5
        while (sub_select_of_army_soldier_ams == 5)
        {
            matryed:
            int sub_option_of_matryed_officers;
            title("HEROES OF OUR NATION");
            to_show_matryed_menu_ams(2);
            sub_option_of_matryed_officers = selecting_function(columns_of_screen / 3 + 10, 17,2);
            if (sub_option_of_matryed_officers == 1)
            {
                system("cls");
                title("HEROES OF OUR NATION");
                to_view_matryed("matryed/ams_army_soldiers_matryed.txt");
                sub_option_of_matryed_officers = yes_or_no(sub_option_of_matryed_officers);
                if(sub_option_of_matryed_officers == 0)
                {
                    goto matryed;
                }
            }
            else if (sub_option_of_matryed_officers == 2)
            {
                title("HEROES OF OUR NATION");
                to_add_matryed("matryed/ams_army_soldiers_matryed.txt");
                sub_option_of_matryed_officers = yes_or_no(sub_option_of_matryed_officers);
                if(sub_option_of_matryed_officers == 0)
                {
                    goto matryed;
                }
            }
            else if (sub_option_of_matryed_officers == 3)
            {
                goto army_soldiers_menu;
            }
        }

        // GO TO AMS TOP MENU IN 6
        if (sub_select_of_army_soldier_ams == 6)
        {
            goto ams_top_menu;
        }
        
    }
    // ARMY OFFICERS IN AMS // complete
    while (main_selected_option_of_ams == 2)
    {
        army_officers_menu:
        title("ARMY TEAM MANAGEMENT SYSTEM");
        to_show_sub_menu_army_officer_ams(7);
        sub_select_of_army_officer_ams = selecting_function(columns_of_screen / 3 + 10, 12,7);
        // View Personal details of Officers 1
        while (sub_select_of_army_officer_ams == 1)
        {
            int check_batch_id;
            int batch_id_idx;
            title("PERSONAL DETAILS OF ARMY OFFICER");
            batch_id_idx = id_take_to_fetch_and_id_check_officer_ams();
            check_batch_id = to_show_personal_details_from_officer_array(batch_id_idx);
            if (check_batch_id == 1)
            {
                sub_select_of_army_officer_ams = yes_or_no(sub_select_of_army_officer_ams);
                if (sub_select_of_army_officer_ams == 0 )
                {
                    goto army_officers_menu;
                }
            }
        }
         // ADD NEW RECORD 2
        while (sub_select_of_army_officer_ams == 2)
        {
            title("ADD DETAILS OF ARMY OFFICER");
            to_show_note("PMI-");
            to_add_data_in_officer_array_ams();
            to_add_data_in_officer_txt_ams();
            sub_select_of_army_officer_ams = yes_or_no(sub_select_of_army_officer_ams);
            if (sub_select_of_army_officer_ams == 0 )
            {
                goto army_officers_menu;
            }
        }
        // EDIT RECORD 3
        while (sub_select_of_army_officer_ams == 3)
        {
            int check_batch_idx;
            int batch_id_index;
            title("EDIT DETAILS OF ARMY SOLDIER");
            batch_id_index = id_take_to_fetch_and_id_check_officer_ams();
            to_edit_data_in_officer_array_ams(batch_id_index);
            to_add_whole_data_in_officer_txt_ams();
            sub_select_of_army_officer_ams = yes_or_no(sub_select_of_army_officer_ams);
            if (sub_select_of_army_officer_ams == 0)
            {
                goto army_officers_menu;
            }
        }
        // RETIRED OFFICERS 4
        while (sub_select_of_army_officer_ams == 4)
        {   retired_main_menu_officer:
            int sub_option_of_retired_officer;
            title("RETIRED OFFICERS MANAGEMENT");
            to_show_retired_menu_ams(2);
            sub_option_of_retired_officer = selecting_function(columns_of_screen / 3 + 10, 17,2);
            // to view retired soldiers
            while(sub_option_of_retired_officer == 1)
            {
                to_view_retired_officer_data_ams();
                sub_option_of_retired_officer = yes_or_no(sub_option_of_retired_officer);
                if(sub_option_of_retired_officer == 0)
                {
                    goto retired_main_menu_officer;
                }
            }
            // to add new retired soldiers
            while(sub_option_of_retired_officer == 2)
            {
                int batch_id_index;
                batch_id_index = id_take_to_fetch_and_id_check_officer_ams();
                to_add_removed_officer_in_retired_ams(batch_id_index);
                to_remove_retired_officer_from_array_ams(batch_id_index);
                to_add_whole_data_in_officer_txt_ams();
                to_add_whole_data_in_retired_officer_txt_ams();
                sub_option_of_retired_officer = yes_or_no(sub_option_of_retired_officer);
                if(sub_option_of_retired_officer == 0)
                {
                    goto retired_main_menu_officer;
                }
            }
            if(sub_option_of_retired_officer == 3)
            {
                goto army_officers_menu;
            }
            
        }
        // MATRYED 5
        while (sub_select_of_army_officer_ams == 5)
        {
            matryed_officer:
            int sub_option_of_matryed_officers;
            title("HEROES OF OUR NATION");
            to_show_matryed_menu_ams(2);
            sub_option_of_matryed_officers = selecting_function(columns_of_screen / 3 + 10, 17,2);
            if (sub_option_of_matryed_officers == 1)
            {
                system("cls");
                title("HEROES OF OUR NATION");
                to_view_matryed("matryed/ams_army_soldiers_matryed.txt");
                sub_option_of_matryed_officers = yes_or_no(sub_option_of_matryed_officers);
                if(sub_option_of_matryed_officers == 0)
                {
                    goto matryed_officer;
                }
            }
            else if (sub_option_of_matryed_officers == 2)
            {
                title("HEROES OF OUR NATION");
                to_add_matryed("matryed/ams_army_soldiers_matryed.txt");
                sub_option_of_matryed_officers = yes_or_no(sub_option_of_matryed_officers);
                if(sub_option_of_matryed_officers == 0)
                {
                    goto matryed_officer;
                }
            }
            else if (sub_option_of_matryed_officers == 3)
            {
                goto army_officers_menu;
            }
        }  
        // Officers in Provience 6
        while (sub_select_of_army_officer_ams == 6)
        {
            string prov; // provience
            int count_officers = 0;
            prov = to_take_provience();
            count_officers = to_see_data_from_ams_officer_arrray(3,prov);
            sub_select_of_army_officer_ams = yes_or_no(sub_select_of_army_officer_ams);
            if(sub_select_of_army_officer_ams == 0)
                {
                    goto army_officers_menu;
                }
        }
        // Soldiers under Officers 7
        while (sub_select_of_army_officer_ams == 7)
        {   
            int batch_id_index;
            string check_batch_id;
            title("SOLDIERS UNDER THE OFFICER");
            soldier_under_officers_ams();
            batch_id_index = id_take_to_fetch_and_id_check_officer_ams();
            soldier_under_officer_view_ams(batch_id_index);
            sub_select_of_army_officer_ams = yes_or_no(sub_select_of_army_officer_ams);
            if(sub_select_of_army_officer_ams == 0)
            {
                goto army_officers_menu;
            }

        }
        // GO TO AGAIN LOG IN 8
        while (sub_select_of_army_officer_ams == 8)
        {
            goto ams_top_menu;
        }
    }
    // ARMY INSTRUMENTS // COMPLETE
    while (main_selected_option_of_ams == 3)
    {
        sub_menu_instruments:
        int sub_of_sub_selected_instruments;
        title("ARMY TEAM MANAGEMENT SYSTEM");
        to_show_sub_menu_army_instruments_ams(5);
        sub_select_of_army_instruments_ams = selecting_function(columns_of_screen / 3 + 10, 12,5);
        // VIEW INSTRUMENTS 1
        while (sub_select_of_army_instruments_ams == 1)
        {   
            instrument_stayer:
            int sub_of_sub_selected_instruments;
            title("INSTRUMENTS MANAGEMENT SYSTEM");
            to_show_sub_detail_view_army_instruments_ams(5);
            sub_of_sub_selected_instruments = selecting_function(columns_of_screen / 3 + 10, 12,5);
            // Carriers
            while (sub_of_sub_selected_instruments == 1)
            {
                to_show_carriers_details();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer;
                }
            }
            // Weapons
            while (sub_of_sub_selected_instruments == 2)
            {
                
                to_show_weapons_details();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer;
                }
            }
            // missiles
            while (sub_of_sub_selected_instruments == 3)
            {
                to_show_missilies_details();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer;
                }
            }
            // tanks
            while (sub_of_sub_selected_instruments == 4)
            {
                to_show_tank_details();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer;
                }
            }
            // atomic Bomb
            while (sub_of_sub_selected_instruments == 5)
            {
                to_show_atomic_bombs_details();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer;
                }
            }
            // back
            while (sub_of_sub_selected_instruments == 6)
            {
                goto sub_menu_instruments;
            }
        }
        // Add INSTRUMENTS
        while (sub_select_of_army_instruments_ams == 2)
        {
            INS_PLACE_2:
            int sub_of_sub_selected_instruments;
            title("INSTRUMENTS MANAGEMENT SYSTEM");
            to_show_sub_detail_view_army_instruments_ams(5);
            sub_of_sub_selected_instruments = selecting_function(columns_of_screen / 3 + 10, 12,5);
            while (sub_of_sub_selected_instruments == 1)
            {
                to_show_carriers_details();
                to_add_data_in_array_carrier();
                to_add_data_of_carrier_in_txt();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto INS_PLACE_2;
                }
            }
            // Weapons
            while (sub_of_sub_selected_instruments == 2)
            {
                
                to_show_weapons_details();
                to_add_data_in_array_weapons();
                to_add_data_of_weapons_in_txt();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto INS_PLACE_2;
                }
            }
            // missiles
            while (sub_of_sub_selected_instruments == 3)
            {
                to_add_data_in_array_missilies();
                to_show_missilies_details();
                to_add_data_of_missilies_in_txt();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto INS_PLACE_2;
                }
            }
            // tanks
            while (sub_of_sub_selected_instruments == 4)
            {
                to_show_tank_details();
                to_add_data_in_array_tank();
                to_add_data_of_tank_in_txt();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto INS_PLACE_2;
                }
            }
            // atomic Bomb
            while (sub_of_sub_selected_instruments == 5)
            {
                to_show_atomic_bombs_details();
                to_add_data_in_array_bomb();
                to_add_data_of_bomb_in_txt();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto INS_PLACE_2;
                }
            }
            // back
            while (sub_of_sub_selected_instruments == 6)
            {
                goto sub_menu_instruments;
            }
            
        }
        // edit instruments
        while(sub_select_of_army_instruments_ams == 3)
        {
            instrument_stayer_edit:
            int sub_of_sub_selected_instruments;
            title("INSTRUMENTS MANAGEMENT SYSTEM");
            to_show_sub_detail_view_army_instruments_ams(5);
            sub_of_sub_selected_instruments = selecting_function(columns_of_screen / 3 + 10, 12,5);
               while (sub_of_sub_selected_instruments == 1)
            {
                to_edit_instrument_record_carriers();
                to_add_whole_data_in_txt_carriers();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer_edit;
                }
            }
            while (sub_of_sub_selected_instruments == 2)
            {
                to_edit_instrument_record_weapons();
                to_add_whole_data_in_txt_weapons();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer_edit;
                }
            }
            while (sub_of_sub_selected_instruments == 3)
            {
                to_edit_instrument_record_missilies();
                to_add_whole_data_in_txt_missilies();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer_edit;
                }
            }
            while (sub_of_sub_selected_instruments == 4)
            {
                to_edit_instrument_record_tank();
                to_add_whole_data_in_txt_tank();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer_edit;
                }
            }
            while (sub_of_sub_selected_instruments == 5)
            {
                to_edit_instrument_record_bombs();
                to_add_whole_data_in_txt_bombs();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer_edit;
                }
            }
            while(sub_of_sub_selected_instruments == 6)
            {
                goto sub_menu_instruments;
            }
            
        }
         // graph
        while (sub_select_of_army_instruments_ams == 4)
        {
            system("cls");
            title("GRAPH OF BUDGET");
            graph_ams();
            Sleep(5000);
            sub_select_of_army_instruments_ams = yes_or_no(sub_select_of_army_instruments_ams);
            if(sub_select_of_army_instruments_ams == 0)
            {
                goto sub_menu_instruments;
            }
        }
        // Budget Calculate
        while (sub_select_of_army_instruments_ams == 5)
        {
            float total;
            title("THE ARMY BUDGET");
            total_ams_budget();
            sub_select_of_army_instruments_ams = yes_or_no(sub_select_of_army_instruments_ams);
            if(sub_select_of_army_instruments_ams == 0)
            {
                goto sub_menu_instruments;
            }
        }
        //Back
        while (sub_selected_instruments == 6 || sub_select_of_army_instruments_ams == 6)
        {
            goto ams_top_menu;
        }
    }
    // CROPS
    while (main_selected_option_of_ams == 4)
    {
        int sub_select_of_crops_ams;
        menu_crops:
        title("CROPS MANAGEMENT SYSTEM");
        to_show_sub_menu_army_crops_ams(2);
        sub_select_of_crops_ams = selecting_function(columns_of_screen / 3 + 10,12,2);
        while(sub_select_of_crops_ams == 1)
        {
            to_show_xxx_khor();
            sub_select_of_crops_ams = yes_or_no(sub_select_of_crops_ams);
            if(sub_select_of_crops_ams == 0)
            {
                goto menu_crops;
            }
        }
        while(sub_select_of_crops_ams == 2)
        {
            to_show_soc_khor();
            sub_select_of_crops_ams = yes_or_no(sub_select_of_crops_ams);
            if(sub_select_of_crops_ams == 0)
            {
                goto menu_crops;
            }
        }
        if (sub_select_of_crops_ams ==  3)
        {
            goto ams_top_menu;
        }
    }
    // Report of work
    while (main_selected_option_of_ams == 5)
    {
        
        to_fetch_feedback();
        main_selected_option_of_ams = yes_or_no(main_selected_option_of_ams);
        if (main_selected_option_of_ams == 0)
        {
            goto ams_top_menu;
        }
    }
}
// 1. ARMY MANAGEMENT SYSTEM ENDED
// 2. NAVY MANAGEMENT SYSTEM
int navy_management_team_system(int checker_of_user_domain)
{
    
    int sub_selected_instruments;
    int main_selected_option_of_nms;
    int sub_select_of_navy_instruments_nms, sub_select_of_navy_soldier_nms, sub_select_of_navy_officer_nms;
    int item_quantity[5];
// Main Menu of NAVY TEAM MANAGEMENT SYSTEM
nms_top_menu:
    title("NAVY TEAM MANAGEMENT SYSTEM");
    to_show_main_menu_nms(5);
    
    main_selected_option_of_nms = selecting_function(columns_of_screen / 3 + 10,12,5);
    // NAVY soldiers in nms // COMPLETE
    while (main_selected_option_of_nms == 1)
    {
    navy_soldiers_menu:
        title("NAVY TEAM MANAGEMENT SYSTEM");
        to_show_sub_menu_navy_soldier_nms(5);
        sub_select_of_navy_soldier_nms = selecting_function(columns_of_screen / 3 + 10,12,5);
        // View Personal details of Soldiers 1
        while (sub_select_of_navy_soldier_nms == 1)
        {
            int check_batch_id;
            int batch_id_idx;
            title("PERSONAL DETAILS OF NAVY SOLDIER");
            batch_id_idx = id_take_to_fetch_and_id_check_soldiers_nms();
            check_batch_id = to_show_personal_details_from_navy_soldiers_array(batch_id_idx);
            if (check_batch_id == 1)
            {
                sub_select_of_navy_soldier_nms = yes_or_no(sub_select_of_navy_soldier_nms);
                if (sub_select_of_navy_soldier_nms == 0 )
                {
                    goto navy_soldiers_menu;
                }
            }
        }
        // ADD NEW RECORD 2
        while (sub_select_of_navy_soldier_nms == 2)
        {
            title("ADD DETAILS OF NAVY SOLDIER");
            to_show_note("121-");
            to_add_data_in_soldiers_array_nms();
            to_add_data_in_soldier_txt_nms();
            sub_select_of_navy_soldier_nms = yes_or_no(sub_select_of_navy_soldier_nms);
            if (sub_select_of_navy_soldier_nms == 0 )
            {
                goto navy_soldiers_menu;
            }
        }
        // EDIT RECORD 3
        while (sub_select_of_navy_soldier_nms == 3)
        {
            int check_batch_idx;
            int batch_id_index;
            title("EDIT DETAILS OF NAVY SOLDIER");
            batch_id_index = id_take_to_fetch_and_id_check_soldiers_nms();
            to_edit_data_in_soldiers_array_nms(batch_id_index);
            to_add_whole_data_in_soldier_txt_nms();
            sub_select_of_navy_soldier_nms = yes_or_no(sub_select_of_navy_soldier_nms);
            if (sub_select_of_navy_soldier_nms == 0)
            {
                goto navy_soldiers_menu;
            }
        }
        // RETIRED OFFICERS 4
        while (sub_select_of_navy_soldier_nms == 4)
        {   retired_main_menu:
            int sub_option_of_retired_soldiers;
            title("RETIRED SOLDIERS MANAGEMENT");
            to_show_retired_menu_nms(2);
            sub_option_of_retired_soldiers = selecting_function(columns_of_screen / 3 + 10, 17,2);
            // to view retired soldiers
            while(sub_option_of_retired_soldiers == 1)
            {
                to_view_retired_soldier_data_nms();
                sub_option_of_retired_soldiers = yes_or_no(sub_option_of_retired_soldiers);
                if(sub_option_of_retired_soldiers == 0)
                {
                    goto retired_main_menu;
                }
            }
            // to add new retired soldiers
            while(sub_option_of_retired_soldiers == 2)
            {
                int batch_id_index;
                batch_id_index = id_take_to_fetch_and_id_check_soldiers_nms();
                to_add_removed_soldier_in_retired_nms(batch_id_index);
                to_remove_retired_soldier_from_array_nms(batch_id_index);
                to_add_whole_data_in_soldier_txt_nms();
                to_add_whole_data_in_retired_soldier_txt_nms();
                sub_option_of_retired_soldiers = yes_or_no(sub_option_of_retired_soldiers);
                if(sub_option_of_retired_soldiers == 0)
                {
                    goto retired_main_menu;
                }
            }

            if(sub_option_of_retired_soldiers == 3)
            {
                goto navy_soldiers_menu;
            }
            
        }
        // MATRYED 5
        while (sub_select_of_navy_soldier_nms == 5)
        {
            matryed:
            int sub_option_of_matryed_officers;
            title("HEROES OF OUR NATION");
            to_show_matryed_menu_nms(2);
            sub_option_of_matryed_officers = selecting_function(columns_of_screen / 3 + 10, 17,2);
            if (sub_option_of_matryed_officers == 1)
            {
                system("cls");
                title("HEROES OF OUR NATION");
                to_view_matryed("matryed/ams_army_soldiers_matryed.txt");
                sub_option_of_matryed_officers = yes_or_no(sub_option_of_matryed_officers);
                if(sub_option_of_matryed_officers == 0)
                {
                    goto matryed;
                }
            }
            else if (sub_option_of_matryed_officers == 2)
            {
                title("HEROES OF OUR NATION");
                to_add_matryed("matryed/ams_army_soldiers_matryed.txt");
                sub_option_of_matryed_officers = yes_or_no(sub_option_of_matryed_officers);
                if(sub_option_of_matryed_officers == 0)
                {
                    goto matryed;
                }
            }
            else if (sub_option_of_matryed_officers == 3)
            {
                goto navy_soldiers_menu;
            }
        }
        // GO TO nms TOP MENU IN 6
        if (sub_select_of_navy_soldier_nms == 6)
        {
            goto nms_top_menu;
        }
        
    }
    // NAVY OFFICERS IN nms // complete
    while (main_selected_option_of_nms == 2)
    {
        navy_officers_menu:
        title("NAVY TEAM MANAGEMENT SYSTEM");
        to_show_sub_menu_navy_officer_nms(7);
        sub_select_of_navy_officer_nms = selecting_function(columns_of_screen / 3 + 10, 12,7);
        // View Personal details of Officers 1
        while (sub_select_of_navy_officer_nms == 1)
        {
            int check_batch_id;
            int batch_id_idx;
            title("PERSONAL DETAILS OF NAVY OFFICER");
            batch_id_idx = id_take_to_fetch_and_id_check_officer_nms();
            check_batch_id = to_show_personal_details_from_navy_officer_array(batch_id_idx);
            if (check_batch_id == 1)
            {
                sub_select_of_navy_officer_nms = yes_or_no(sub_select_of_navy_officer_nms);
                if (sub_select_of_navy_officer_nms == 0 )
                {
                    goto navy_officers_menu;
                }
            }
        }
         // ADD NEW RECORD 2
        while (sub_select_of_navy_officer_nms == 2)
        {
            title("ADD DETAILS OF NAVY OFFICER");
            to_show_note("NAV-");
            to_add_data_in_officer_array_nms();
            to_add_data_in_officer_txt_nms();
            sub_select_of_navy_officer_nms = yes_or_no(sub_select_of_navy_officer_nms);
            if (sub_select_of_navy_officer_nms == 0 )
            {
                goto navy_officers_menu;
            }
        }
        // EDIT RECORD 3
        while (sub_select_of_navy_officer_nms == 3)
        {
            int check_batch_idx;
            int batch_id_index;
            title("EDIT DETAILS OF NAVY SOLDIER");
            batch_id_index = id_take_to_fetch_and_id_check_officer_nms();
            to_edit_data_in_officer_array_nms(batch_id_index);
            to_add_whole_data_in_officer_txt_nms();
            sub_select_of_navy_officer_nms = yes_or_no(sub_select_of_navy_officer_nms);
            if (sub_select_of_navy_officer_nms == 0)
            {
                goto navy_officers_menu;
            }
        }
        // RETIRED OFFICERS 4
        while (sub_select_of_navy_officer_nms == 4)
        {   retired_main_menu_officer:
            int sub_option_of_retired_officer;
            title("RETIRED OFFICERS MANAGEMENT");
            to_show_retired_menu_nms(2);
            sub_option_of_retired_officer = selecting_function(columns_of_screen / 3 + 10, 17,2);
            // to view retired soldiers
            while(sub_option_of_retired_officer == 1)
            {
                to_view_retired_officer_data_nms();
                sub_option_of_retired_officer = yes_or_no(sub_option_of_retired_officer);
                if(sub_option_of_retired_officer == 0)
                {
                    goto retired_main_menu_officer;
                }
            }
            // to add new retired soldiers
            while(sub_option_of_retired_officer == 2)
            {
                int batch_id_index;
                batch_id_index = id_take_to_fetch_and_id_check_officer_nms();
                to_add_removed_officer_in_retired_nms(batch_id_index);
                to_remove_retired_officer_from_array_nms(batch_id_index);
                to_add_whole_data_in_officer_txt_nms();
                to_add_whole_data_in_retired_officer_txt_nms();
                sub_option_of_retired_officer = yes_or_no(sub_option_of_retired_officer);
                if(sub_option_of_retired_officer == 0)
                {
                    goto retired_main_menu_officer;
                }
            }
            if(sub_option_of_retired_officer == 3)
            {
                goto navy_officers_menu;
            }
            
        }
        // MATRYED 5
        while (sub_select_of_navy_officer_nms == 5)
        {
            matryed_officer:
            int sub_option_of_matryed_officers;
            title("HEROES OF OUR NATION");
            to_show_matryed_menu_nms(2);
            sub_option_of_matryed_officers = selecting_function(columns_of_screen / 3 + 10, 17,2);
            if (sub_option_of_matryed_officers == 1)
            {
                system("cls");
                title("HEROES OF OUR NATION");
                to_view_matryed("matryed/ams_army_soldiers_matryed.txt");
                sub_option_of_matryed_officers = yes_or_no(sub_option_of_matryed_officers);
                if(sub_option_of_matryed_officers == 0)
                {
                    goto matryed_officer;
                }
            }
            else if (sub_option_of_matryed_officers == 2)
            {
                title("HEROES OF OUR NATION");
                to_add_matryed("matryed/ams_army_soldiers_matryed.txt");
                sub_option_of_matryed_officers = yes_or_no(sub_option_of_matryed_officers);
                if(sub_option_of_matryed_officers == 0)
                {
                    goto matryed_officer;
                }
            }
            else if (sub_option_of_matryed_officers == 3)
            {
                goto navy_officers_menu;
            }
        }  
        // Officers in Provience 6
        while (sub_select_of_navy_officer_nms == 6)
        {
            string prov; // provience
            int count_officers = 0;
            prov = to_take_provience();
            count_officers = to_see_data_from_nms_officer_arrray(3,prov);
            sub_select_of_navy_officer_nms = yes_or_no(sub_select_of_navy_officer_nms);
            if(sub_select_of_navy_officer_nms == 0)
                {
                    goto navy_officers_menu;
                }
        }
        // Soldiers under Officers 7
        while (sub_select_of_navy_officer_nms == 7)
        {   
            int batch_id_index;
            string check_batch_id;
            title("SOLDIERS UNDER THE OFFICER");
            soldier_under_officers_nms();
            batch_id_index = id_take_to_fetch_and_id_check_officer_nms();
            soldier_under_officer_view_nms(batch_id_index);
            sub_select_of_navy_officer_nms = yes_or_no(sub_select_of_navy_officer_nms);
            if(sub_select_of_navy_officer_nms == 0)
            {
                goto navy_officers_menu;
            }

        }
        // GO TO AGAIN LOG IN 8
        while (sub_select_of_navy_officer_nms == 8)
        {
            goto nms_top_menu;
        }
    }
    // NAVY INSTRUMENTS // COMPLETE
    while (main_selected_option_of_nms == 3)
    {
        sub_menu_instruments:
        int sub_of_sub_selected_instruments;
        title("NAVY TEAM MANAGEMENT SYSTEM");
        to_show_sub_menu_navy_instruments_nms(5);
        sub_select_of_navy_instruments_nms = selecting_function(columns_of_screen / 3 + 10, 12,5);
        // VIEW INSTRUMENTS 1
        while (sub_select_of_navy_instruments_nms == 1)
        {   
            instrument_stayer:
            int sub_of_sub_selected_instruments;
            title("INSTRUMENTS MANAGEMENT SYSTEM");
            to_show_sub_detail_view_navy_instruments_nms(5);
            sub_of_sub_selected_instruments = selecting_function(columns_of_screen / 3 + 10, 12,5);
            // air_craft
            while (sub_of_sub_selected_instruments == 1)
            {
                to_show_air_craft_details();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer;
                }
            }
            // Weapons
            while (sub_of_sub_selected_instruments == 2)
            {
                
                to_show_weapons_details_navy();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer;
                }
            }
            // missiles
            while (sub_of_sub_selected_instruments == 3)
            {
                to_show_missilies_details_navy();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer;
                }
            }
            // subarines
            while (sub_of_sub_selected_instruments == 4)
            {
                to_show_subarine_details();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer;
                }
            }
            // atomic surface_ship
            while (sub_of_sub_selected_instruments == 5)
            {
                to_show_surface_ships_details();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer;
                }
            }
            // back
            while (sub_of_sub_selected_instruments == 6)
            {
                goto sub_menu_instruments;
            }
        }
        // Add INSTRUMENTS
        while (sub_select_of_navy_instruments_nms == 2)
        {
            INS_PLACE_2:
            int sub_of_sub_selected_instruments;
            title("INSTRUMENTS MANAGEMENT SYSTEM");
            to_show_sub_detail_view_navy_instruments_nms(5);
            sub_of_sub_selected_instruments = selecting_function(columns_of_screen / 3 + 10, 12,5);
            while (sub_of_sub_selected_instruments == 1)
            {
                to_show_air_craft_details();
                to_add_data_in_array_air_craft();
                to_add_data_of_air_craft_in_txt();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto INS_PLACE_2;
                }
            }
            // Weapons
            while (sub_of_sub_selected_instruments == 2)
            {
                
                to_show_weapons_details_navy();
                to_add_data_in_array_weapons_navy();
                to_add_data_of_weapons_in_txt_navy();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto INS_PLACE_2;
                }
            }
            // missiles
            while (sub_of_sub_selected_instruments == 3)
            {
                to_show_missilies_details_navy();
                to_add_data_in_array_missilies_navy();
                to_add_data_of_missilies_in_txt_navy();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto INS_PLACE_2;
                }
            }
            // subarines
            while (sub_of_sub_selected_instruments == 4)
            {
                to_show_subarine_details();
                to_add_data_in_array_subarine();
                to_add_data_of_subarine_in_txt();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto INS_PLACE_2;
                }
            }
            // atomic surface_ship
            while (sub_of_sub_selected_instruments == 5)
            {
                to_show_surface_ships_details();
                to_add_data_in_array_surface_ship();
                to_add_data_of_surface_ship_in_txt();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto INS_PLACE_2;
                }
            }
            // back
            while (sub_of_sub_selected_instruments == 6)
            {
                goto sub_menu_instruments;
            }
            
        }
        // edit instruments
        while(sub_select_of_navy_instruments_nms == 3)
        {
            instrument_stayer_edit:
            int sub_of_sub_selected_instruments;
            title("INSTRUMENTS MANAGEMENT SYSTEM");
            to_show_sub_detail_view_navy_instruments_nms(5);
            sub_of_sub_selected_instruments = selecting_function(columns_of_screen / 3 + 10, 12,5);
               while (sub_of_sub_selected_instruments == 1)
            {
                to_edit_instrument_record_air_craft();
                to_add_whole_data_in_txt_air_craft();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer_edit;
                }
            }
            while (sub_of_sub_selected_instruments == 2)
            {
                to_edit_instrument_record_weapons_navy();
                to_add_whole_data_in_txt_weapons_navy();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer_edit;
                }
            }
            while (sub_of_sub_selected_instruments == 3)
            {
                to_edit_instrument_record_missilies_navy();
                to_add_whole_data_in_txt_missilies_navy();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer_edit;
                }
            }
            while (sub_of_sub_selected_instruments == 4)
            {
                to_edit_instrument_record_subarine();
                to_add_whole_data_in_txt_subarine();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer_edit;
                }
            }
            while (sub_of_sub_selected_instruments == 5)
            {
                to_edit_instrument_record_surface_ships();
                to_add_whole_data_in_txt_surface_ships();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer_edit;
                }
            }
            while(sub_of_sub_selected_instruments == 6)
            {
                goto sub_menu_instruments;
            }
            
        }
         // graph
        while (sub_select_of_navy_instruments_nms == 4)
        {
            system("cls");
            title("GRAPH OF BUDGET");
            graph_nms();
            Sleep(5000);
            sub_select_of_navy_instruments_nms = yes_or_no(sub_select_of_navy_instruments_nms);
            if(sub_select_of_navy_instruments_nms == 0)
            {
                goto sub_menu_instruments;
            }
        }
        // Budget Calculate
        while (sub_select_of_navy_instruments_nms == 5)
        {
            float total;
            title("THE NAVY BUDGET");
            total_nms_budget();
            sub_select_of_navy_instruments_nms = yes_or_no(sub_select_of_navy_instruments_nms);
            if(sub_select_of_navy_instruments_nms == 0)
            {
                goto sub_menu_instruments;
            }
        }
        //Back
        while (sub_selected_instruments == 6 || sub_select_of_navy_instruments_nms == 6)
        {
            goto nms_top_menu;
        }
    }
    
    // CROPS
    while (main_selected_option_of_nms == 4)
    {
        int sub_select_of_crops_nms;
        menu_crops:
        title("CROPS MANAGEMENT SYSTEM");
        to_show_sub_menu_navy_crops_nms(2);
        sub_select_of_crops_nms = selecting_function(columns_of_screen / 3 + 10,12,2);
        while(sub_select_of_crops_nms == 1)
        {
            to_show_naval_khor();
            sub_select_of_crops_nms = yes_or_no(sub_select_of_crops_nms);
            if(sub_select_of_crops_nms == 0)
            {
                goto menu_crops;
            }
        }
        while(sub_select_of_crops_nms == 2)
        {
            to_show_naizi_khor();
            sub_select_of_crops_nms = yes_or_no(sub_select_of_crops_nms);
            if(sub_select_of_crops_nms == 0)
            {
                goto menu_crops;
            }
        }
        if (sub_select_of_crops_nms ==  3)
        {
            goto nms_top_menu;
        }
    }
    // Report of work
    while (main_selected_option_of_nms == 5)
    {
        
        to_fetch_feedback();
        main_selected_option_of_nms = yes_or_no(main_selected_option_of_nms);
        if (main_selected_option_of_nms == 0)
        {
            goto nms_top_menu;
        }
    }
}
// 2. NAVY MANAGEMENT SYSTEM ENDED
// 3. AIR FORCE MANAGEMENT SYSTEM
int air_force_management_team_system(int checker_of_user_domain)
{
    
    int sub_selected_instruments;
    int main_selected_option_of_afms;
    int sub_select_of_air_force_instruments_afms, sub_select_of_air_force_soldier_afms, sub_select_of_air_force_officer_afms;
    int item_quantity[5];
// Main Menu of AIR FORCE TEAM MANAGEMENT SYSTEM
afms_top_menu:
    title("AIR FORCE TEAM MANAGEMENT SYSTEM");
    to_show_main_menu_afms(5);
    
    main_selected_option_of_afms = selecting_function(columns_of_screen / 3 + 10,12,5);
    // AIR FORCE soldiers in afms // COMPLETE
    while (main_selected_option_of_afms == 1)
    {
    air_force_soldiers_menu:
        title("AIR FORCE TEAM MANAGEMENT SYSTEM");
        to_show_sub_menu_air_force_soldier_afms(5);
        sub_select_of_air_force_soldier_afms = selecting_function(columns_of_screen / 3 + 10,12,5);
        // View Personal details of Soldiers 1
        while (sub_select_of_air_force_soldier_afms == 1)
        {
            int check_batch_id;
            int batch_id_idx;
            title("PERSONAL DETAILS OF AIR FORCE SOLDIER");
