open Sys
open Utility 

(** for now just create the directory structure *)
let init (): unit =
  let contents = Digest.to_hex "hello" in
  if is_directory "./.it" then
    create_file ".it/HEAD" ~contents:contents ()
  else
    Unix.mkdir ".it" 0o755;
    create_file ".it/HEAD" ~contents:contents ()
  
let add (): unit =
  ()

(** dump the contents of the logfile which keeps track of commits *)
let log (): unit =
  let ic = open_in "./.it/log" in
  print_endline (really_input_string ic (in_channel_length ic))

let commit (): unit =
  ()

let handle_command (command : string): unit = 
  print_endline command;
  match command with
  | "init" -> init ()
  | "add" -> add ()
  | "log" -> log ()
  | "commit" -> commit ()
  | _ -> Printf.fprintf stderr "ERROR: invalid command"

let () =
  if Array.length argv > 1 then
    let command = argv.(1) in
    handle_command command
  else
    Printf.fprintf stderr "ERROR: failure to pass a command"

