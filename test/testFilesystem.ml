open Mlcpp_filesystem

module Testing = struct
  let get_cwd = Filesystem.Path.to_string @@ Filesystem.get_cwd ()
  let set_cwd = fun sfp -> Filesystem.set_cwd @@ Filesystem.Path.from_string sfp
  let copy = fun sfp1 sfp2 -> Filesystem.copy (Filesystem.Path.from_string sfp1) (Filesystem.Path.from_string sfp2)
  let copy_file = fun sfp1 sfp2 -> Filesystem.copy_file (Filesystem.Path.from_string sfp1) (Filesystem.Path.from_string sfp2)
  let create_symlink = fun sfp1 sfp2 -> Filesystem.create_symlink (Filesystem.Path.from_string sfp1) (Filesystem.Path.from_string sfp2)
  let create_directory = fun sfp -> Filesystem.create_directory @@ Filesystem.Path.from_string sfp
  let create_directories = fun sfp -> Filesystem.create_directories @@ Filesystem.Path.from_string sfp

end

(* Tests *)

let test_get_cwd () =
  Alcotest.(check string) "get_cwd = Sys.getcwd" (Sys.getcwd ()) (Testing.get_cwd)

let test_set_cwd () =
  Alcotest.(check bool) "set_cwd works" true
  (let cwd = Filesystem.get_cwd () in
   if Testing.set_cwd ".."
   then Filesystem.set_cwd cwd  (* restore *)
   else false
  )

let test_copy_known () =
  Alcotest.(check bool) "copy a known file" true (Testing.copy "test.exe" "test_exe.backup")

let test_copy_unknown () =
  Alcotest.(check bool) "copy a known file" false (Testing.copy "test42.exe" "test_exe.some")

let test_copy_file () =
  Alcotest.(check bool) "copy an unknown file" false (Testing.copy_file "test42.exe" "test_exe.unk")

let test_symlink_known () =
  Alcotest.(check bool) "symlink a known file" true (Testing.create_symlink "test.exe" "test_exe.link")

let test_symlink_unknown () =
  Alcotest.(check bool)
  "symlink an unknown file succeeds"
  true (* == *) (Testing.create_symlink "test876.exe" "test_exe.unk")

let test_create_directory () =
  Alcotest.(check bool) "create a single directory" true (Testing.create_directory "./d_042")

let test_create_directory_fails () =
  Alcotest.(check bool) "try create deep directories" false (Testing.create_directory "./d_007/d_005/d_003")

let test_create_directories () =
  Alcotest.(check bool) "create deep directories" true (Testing.create_directories "./d_1/d_2/d_3")


(* Runner *)

let test =
  let open Alcotest in
  "ML Cpp Filesystem",
  [
    test_case "get current working dir" `Quick test_get_cwd;
    test_case "set current working dir" `Quick test_set_cwd;
    test_case "copy a known file" `Quick test_copy_known;
    test_case "copy an unknown file" `Quick test_copy_unknown;
    test_case "copy_file an unknown file" `Quick  test_copy_file;
    test_case "symlink a known file" `Quick  test_symlink_known;
    test_case "symlink an unknown file" `Quick  test_symlink_unknown;
    test_case "create dir" `Quick test_create_directory;
    test_case "fail to create deep dir" `Quick test_create_directory_fails;
    test_case "create deep dir" `Quick test_create_directories;
  ]