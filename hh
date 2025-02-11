How Naming Is Managed in CI/CD
Branch	Version Generated	Stored As
feature/foo	1.0.1234-SNAPSHOT	my-app-1.0.1234-SNAPSHOT.jar
main (release)	1.0.1234	my-app-1.0.1234.jar
tag v1.0.0	1.0.0	my-app-1.0.0.jar



✅ Single Build Across Stages (no re-compilation).
✅ Consistent Versioning using GitLab pipeline ID.
✅ Promotion Without Rebuilding (SNAPSHOT to RELEASE).
✅ Deploy the Published Artifact, ensuring production consistency.

 Key Benefits
✅ No double builds – the same artifact is promoted.
✅ No unnecessary rebuilds on main – avoids mismatches.
✅ Ensures traceability – all builds are tracked by CI_PIPELINE_ID.
✅ Repository-driven promotion – handled via Nexus/Artifactory API.
