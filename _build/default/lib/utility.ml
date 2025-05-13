(* walk the file path *)
let rec walk_directory path f =
  let entries = Sys.readdir path in
  Array.iter (fun entry ->
    let full_path = Filename.concat path entry in
    if Sys.is_directory full_path then
      walk_directory full_path f
    else
      f full_path
  ) entries

(* create a file can add contents to the file as well *)
let create_file filename ?(contents = "") () =
  let oc = open_out filename in
  output_string oc contents;
  close_out oc

