open Mlcpp_filesystem

let () =
  let open Alcotest in
  Printf.printf "running tests in dir '%s'\n" (Filesystem.Path.to_string @@ Filesystem.get_cwd ());
  run "ML Cpp Filesystem" [
    TestFilesystem.test;
    TestPath.test;
    TestPermissions.test;
  ]